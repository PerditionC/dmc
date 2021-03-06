// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1993 Microsoft Corporation
// All rights reserved.

// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and Microsoft
// QuickHelp and/or WinHelp documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"

#ifdef AFX_CORE3_SEG
#pragma code_seg(AFX_CORE3_SEG)
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataExchange member functions (contructor is in wincore.cpp for swap tuning)

HWND CDataExchange::PrepareEditCtrl(int nIDC)
{
	HWND hWndCtrl = PrepareCtrl(nIDC);
	ASSERT(hWndCtrl != NULL);
	m_bEditLastControl = TRUE;
	return hWndCtrl;
}

HWND CDataExchange::PrepareCtrl(int nIDC)
{
	ASSERT(nIDC != 0);
	ASSERT(nIDC != -1); // not allowed
	HWND hWndCtrl = ::GetDlgItem(m_pDlgWnd->m_hWnd, nIDC);
	if (hWndCtrl == NULL)
	{
		TRACE1("Error: no data exchange control with ID 0x%04X\n", nIDC);
		ASSERT(FALSE);
		AfxThrowNotSupportedException();
	}
	m_hWndLastControl = hWndCtrl;
	m_bEditLastControl = FALSE; // not an edit item by default
	ASSERT(hWndCtrl != NULL);       // never return NULL handle
	return hWndCtrl;
}

void CDataExchange::Fail()
{
	if (!m_bSaveAndValidate)
	{
		TRACE0("Warning: CDataExchange::Fail called when not validating\n");
		// throw the exception anyway
	}
	else if (m_hWndLastControl != NULL)
	{
		// restore focus and selection to offending field
		::SetFocus(m_hWndLastControl);
		if (m_bEditLastControl) // select edit item
			::SendMessage(m_hWndLastControl, EM_SETSEL, 0, MAKELPARAM(0, -1));
	}
	else
	{
		TRACE0("Error: fail validation with no control to restore focus to\n");
		// do nothing more
	}

	AfxThrowUserException();
}

/////////////////////////////////////////////////////////////////////////////
// Notes for implementing dialog data exchange and validation procs:
//  * always start with PrepareCtrl or PrepareEditCtrl
//  * always start with 'pDX->m_bSaveAndValidate' check
//  * pDX->Fail() will throw an exception - so be prepared
//  * try to avoid creating temporary HWNDs for dialog controls - i.e.
//          use HWNDs for child elements
//  * validation procs should only act if 'm_bSaveAndValidate'
//  * use the suffices:
//          DDX_ = exchange proc
//          DDV_ = validation proc
//
/////////////////////////////////////////////////////////////////////////////

// only supports '%d', '%u', '%ld' and '%lu'
static BOOL PASCAL NEAR _AfxSimpleScanf(const char* pszText,
	const char* pszFormat, void* pData)
{
	ASSERT(pszText != NULL);
	ASSERT(pszFormat != NULL);
	ASSERT(pData != NULL);

	ASSERT(*pszFormat == '%');
	pszFormat++;        // skip '%'

	BOOL bLong = FALSE;
	if (*pszFormat == 'l')
	{
		bLong = TRUE;
		pszFormat++;
	}

	ASSERT(*pszFormat == 'd' || *pszFormat == 'u');
	ASSERT(pszFormat[1] == '\0');

	while (*pszText == ' ' || *pszText == '\t')
		pszText++;
	ASSERT(!_AfxIsDBCSLeadByte(*pszText));
	char chFirst = pszText[0];
	long l, l2;
	if (*pszFormat == 'd')
	{
		// signed
		l = strtol(pszText, (char**)&pszText, 10);
		l2 = (int)l;
	}
	else
	{
		// unsigned
		l = (long)strtoul(pszText, (char**)&pszText, 10);
		l2 = (unsigned int)l;
	}
	if (l == 0 && chFirst != '0')
		return FALSE;   // could not convert

	while (*pszText == ' ' || *pszText == '\t')
		pszText++;
	ASSERT(!_AfxIsDBCSLeadByte(*pszText));
	if (*pszText != '\0')
		return FALSE;   // not terminated properly

	if (bLong)
		*((long*)pData) = l;
	else if (l == l2)
		*((int*)pData) = (int)l;
	else
		return FALSE;       // too big for int

	// all ok
	return TRUE;
}


static void PASCAL NEAR DDX_TextWithFormat(CDataExchange* pDX, int nIDC,
	void* pData, const char* pszFormat, UINT nIDPrompt)
	// only supports windows output formats - no floating point
{
	HWND hWndCtrl = pDX->PrepareEditCtrl(nIDC);
	char szT[64];
	if (pDX->m_bSaveAndValidate)
	{
		// the following works for %d, %u, %ld, %lu
		::GetWindowText(hWndCtrl, szT, sizeof(szT));
		if (!_AfxSimpleScanf(szT, pszFormat, pData))
		{
			AfxMessageBox(nIDPrompt);
			pDX->Fail();        // throws exception
		}
	}
	else
	{
		wvsprintf(szT, pszFormat, pData);
			// does not support floating point numbers - see dlgfloat.cpp
		_AfxSmartSetWindowText(hWndCtrl, szT);
	}
}

/////////////////////////////////////////////////////////////////////////////
// Simple formatting to text item

void AFXAPI DDX_Text(CDataExchange* pDX, int nIDC, BYTE& value)
{
	int n = (int)value;
	DDX_TextWithFormat(pDX, nIDC, &n, "%u", AFX_IDP_PARSE_INT);
	if (pDX->m_bSaveAndValidate)
	{
		if (n > 255)
		{
			AfxMessageBox(AFX_IDP_PARSE_INT);
			pDX->Fail();        // throws exception
		}
		value = (BYTE)n;
	}
}

void AFXAPI DDX_Text(CDataExchange* pDX, int nIDC, int& value)
{
	DDX_TextWithFormat(pDX, nIDC, &value, "%d", AFX_IDP_PARSE_INT);
}

void AFXAPI DDX_Text(CDataExchange* pDX, int nIDC, UINT& value)
{
	DDX_TextWithFormat(pDX, nIDC, &value, "%u", AFX_IDP_PARSE_INT);
}

void AFXAPI DDX_Text(CDataExchange* pDX, int nIDC, long& value)
{
	DDX_TextWithFormat(pDX, nIDC, &value, "%ld", AFX_IDP_PARSE_INT);
}

void AFXAPI DDX_Text(CDataExchange* pDX, int nIDC, DWORD& value)
{
	DDX_TextWithFormat(pDX, nIDC, &value, "%lu", AFX_IDP_PARSE_INT);
}

void AFXAPI DDX_Text(CDataExchange* pDX, int nIDC, CString& value)
{
	HWND hWndCtrl = pDX->PrepareEditCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
	{
		int nLen = ::GetWindowTextLength(hWndCtrl);
		::GetWindowText(hWndCtrl, value.GetBufferSetLength(nLen), nLen+1);
	}
	else
	{
		_AfxSmartSetWindowText(hWndCtrl, value);
	}
}

/////////////////////////////////////////////////////////////////////////////
// Data exchange for special control

void AFXAPI DDX_Check(CDataExchange* pDX, int nIDC, int& value)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
	{
		value = (int)::SendMessage(hWndCtrl, BM_GETCHECK, 0, 0L);
		ASSERT(value >= 0 && value <= 2);
	}
	else
	{
		if (value < 0 || value > 2)
		{
			value = 0;      // default to off
			TRACE1("Warning: dialog data checkbox value out of range"
					" %d\n", value);
		}
		::SendMessage(hWndCtrl, BM_SETCHECK, (WPARAM)value, 0L);
	}
}

void AFXAPI DDX_Radio(CDataExchange* pDX, int nIDC, int& value)
	// must be first in a group of auto radio buttons
{
	HWND hWndFirstCtrl = pDX->PrepareCtrl(nIDC);

	ASSERT(::GetWindowLong(hWndFirstCtrl, GWL_STYLE) & WS_GROUP);
	ASSERT((::GetWindowLong(hWndFirstCtrl, GWL_STYLE) & 0xf)
			== BS_AUTORADIOBUTTON);

	if (pDX->m_bSaveAndValidate)
		value = -1;         // value if none found

	// walk all children in group
	HWND hWndCtrl = hWndFirstCtrl;
	int iButton = 0;
	do
	{
		if (::SendMessage(hWndCtrl, WM_GETDLGCODE, 0, 0L) & DLGC_RADIOBUTTON)
		{
			// control in group is a radio button
			if (pDX->m_bSaveAndValidate)
			{
				if (::SendMessage(hWndCtrl, BM_GETCHECK, 0, 0L) != 0)
				{
					ASSERT(value == -1);    // only set once
					value = iButton;
				}
			}
			else
			{
				// select button
				::SendMessage(hWndCtrl, BM_SETCHECK, (iButton == value), 0L);
			}
			iButton++;
		}
		else
		{
			TRACE0("Warning: skipping non-radio button in group\n");
		}
		hWndCtrl = ::GetNextDlgGroupItem(pDX->m_pDlgWnd->m_hWnd,
			hWndCtrl, FALSE);       // get next
	} while (hWndCtrl != hWndFirstCtrl);
}

/////////////////////////////////////////////////////////////////////////////
// Listboxes, comboboxes

void AFXAPI DDX_LBString(CDataExchange* pDX, int nIDC, CString& value)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
	{
		int nIndex = (int)::SendMessage(hWndCtrl, LB_GETCURSEL, 0, 0L);
		if (nIndex != -1)
		{
			int nLen = (int)::SendMessage(hWndCtrl, LB_GETTEXTLEN, nIndex, 0L);
			::SendMessage(hWndCtrl, LB_GETTEXT, nIndex,
					(LPARAM)(LPSTR)value.GetBufferSetLength(nLen));
		}
		else
		{
			// no selection
			value.Empty();
		}
	}
	else
	{
		// set current selection based on data string
		if (::SendMessage(hWndCtrl, LB_SELECTSTRING, (WPARAM)-1,
		  (LPARAM)(LPCSTR)value) == LB_ERR)
		{
			// no selection match
			TRACE0("Warning: no listbox item selected\n");
		}
	}
}

// Win 3.1 only
void AFXAPI DDX_LBStringExact(CDataExchange* pDX, int nIDC, CString& value)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
	{
		DDX_LBString(pDX, nIDC, value);
	}
	else
	{
		// set current selection based on data string
		int i = (int)::SendMessage(hWndCtrl, LB_FINDSTRINGEXACT, (WPARAM)-1,
		  (LPARAM)(LPCSTR)value);
		if (i < 0)
		{
			// no selection match
			TRACE0("Warning: no listbox item selected\n");
		}
		else
		{
			// select it
			SendMessage(hWndCtrl, LB_SETCURSEL, i, 0L);
		}
	}
}

void AFXAPI DDX_CBString(CDataExchange* pDX, int nIDC, CString& value)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
	{
		// just get current edit item text (or drop list static)
		int nLen = ::GetWindowTextLength(hWndCtrl);
		if (nLen != -1)
		{
			// get known length
			::GetWindowText(hWndCtrl, value.GetBufferSetLength(nLen), nLen+1);
		}
		else
		{
			// for drop lists GetWindowTextLength does not work - assume
			//  max of 255 characters
			::GetWindowText(hWndCtrl, value.GetBuffer(255), 255+1);
			value.ReleaseBuffer();
		}
	}
	else
	{
		// set current selection based on model string
		if (::SendMessage(hWndCtrl, CB_SELECTSTRING, (WPARAM)-1,
			(LPARAM)(LPCSTR)value) == CB_ERR)
		{
			// just set the edit text (will be ignored if DROPDOWNLIST)
			_AfxSmartSetWindowText(hWndCtrl, value);
		}
	}
}

// Win 3.1 only
void AFXAPI DDX_CBStringExact(CDataExchange* pDX, int nIDC, CString& value)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
	{
		DDX_CBString(pDX, nIDC, value);
	}
	else
	{
		// set current selection based on data string
		int i = (int)::SendMessage(hWndCtrl, CB_FINDSTRINGEXACT, (WPARAM)-1,
		  (LPARAM)(LPCSTR)value);
		if (i < 0)
		{
			// no selection match
			TRACE0("Warning: no combobox item selected\n");
		}
		else
		{
			// select it
			SendMessage(hWndCtrl, CB_SETCURSEL, i, 0L);
		}
	}
}

void AFXAPI DDX_LBIndex(CDataExchange* pDX, int nIDC, int& index)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
		index = (int)::SendMessage(hWndCtrl, LB_GETCURSEL, 0, 0L);
	else
		::SendMessage(hWndCtrl, LB_SETCURSEL, (WPARAM)index, 0L);
}

void AFXAPI DDX_CBIndex(CDataExchange* pDX, int nIDC, int& index)
{
	HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
	if (pDX->m_bSaveAndValidate)
		index = (int)::SendMessage(hWndCtrl, CB_GETCURSEL, 0, 0L);
	else
		::SendMessage(hWndCtrl, CB_SETCURSEL, (WPARAM)index, 0L);
}

/////////////////////////////////////////////////////////////////////////////
// Range Dialog Data Validation

static void NEAR PASCAL FailMinMaxWithFormat(CDataExchange* pDX,
	 long minVal, long maxVal, const char* pszFormat, UINT nIDPrompt)
	// error string must have '%1' and '%2' strings for min and max values
	// wsprintf formatting uses long values (format should be '%ld' or '%lu')
{
	ASSERT(pszFormat != NULL);

	if (!pDX->m_bSaveAndValidate)
	{
		TRACE0("Warning: initial dialog data is out of range\n");
		return;     // don't stop now
	}
	char szMin[32];
	char szMax[32];
	wsprintf(szMin, pszFormat, minVal);
	wsprintf(szMax, pszFormat, maxVal);
	CString prompt;
	AfxFormatString2(prompt, nIDPrompt, szMin, szMax);
	AfxMessageBox(prompt, MB_ICONEXCLAMATION, nIDPrompt);
	prompt.Empty(); // exception prep
	pDX->Fail();
}

//NOTE: don't use overloaded function names to avoid type ambiguities
void AFXAPI DDV_MinMaxByte(CDataExchange* pDX, BYTE value, BYTE minVal, BYTE maxVal)
{
	ASSERT(minVal <= maxVal);
	if (value < minVal || value > maxVal)
		FailMinMaxWithFormat(pDX, (long)minVal, (long)maxVal, "%u",
			AFX_IDP_PARSE_INT_RANGE);
}

void AFXAPI DDV_MinMaxInt(CDataExchange* pDX, int value, int minVal, int maxVal)
{
	ASSERT(minVal <= maxVal);
	if (value < minVal || value > maxVal)
		FailMinMaxWithFormat(pDX, (long)minVal, (long)maxVal, "%ld",
			AFX_IDP_PARSE_INT_RANGE);
}

void AFXAPI DDV_MinMaxLong(CDataExchange* pDX, long value, long minVal, long maxVal)
{
	ASSERT(minVal <= maxVal);
	if (value < minVal || value > maxVal)
		FailMinMaxWithFormat(pDX, (long)minVal, (long)maxVal, "%ld",
			AFX_IDP_PARSE_INT_RANGE);
}

void AFXAPI DDV_MinMaxUInt(CDataExchange* pDX, UINT value, UINT minVal, UINT maxVal)
{
	ASSERT(minVal <= maxVal);
	if (value < minVal || value > maxVal)
		FailMinMaxWithFormat(pDX, (long)minVal, (long)maxVal, "%lu",
			AFX_IDP_PARSE_INT_RANGE);
}

void AFXAPI DDV_MinMaxDWord(CDataExchange* pDX, DWORD value, DWORD minVal, DWORD maxVal)
{
	ASSERT(minVal <= maxVal);
	if (value < minVal || value > maxVal)
		FailMinMaxWithFormat(pDX, (long)minVal, (long)maxVal, "%lu",
			AFX_IDP_PARSE_INT_RANGE);
}

/////////////////////////////////////////////////////////////////////////////
// Max Chars Dialog Data Validation

void AFXAPI DDV_MaxChars(CDataExchange* pDX, CString const& value, int nChars)
{
	ASSERT(nChars >= 1);        // allow them something
	if (pDX->m_bSaveAndValidate && value.GetLength() > nChars)
	{
		char szT[32];
		wsprintf(szT, "%d", nChars);
		CString prompt;
		AfxFormatString1(prompt, AFX_IDP_PARSE_STRING_SIZE, szT);
		AfxMessageBox(prompt, MB_ICONEXCLAMATION, AFX_IDP_PARSE_STRING_SIZE);
		prompt.Empty(); // exception prep
		pDX->Fail();
	}
}

/////////////////////////////////////////////////////////////////////////////
// Special DDX_ proc for subclassing controls

void AFXAPI DDX_Control(CDataExchange* pDX, int nIDC, CWnd& rControl)
{
	if (rControl.m_hWnd == NULL)    // not subclassed yet
	{
		ASSERT(!pDX->m_bSaveAndValidate);
		HWND hWndCtrl = pDX->PrepareCtrl(nIDC);
		if (!rControl.SubclassWindow(hWndCtrl))
		{
			ASSERT(FALSE);      // possibly trying to subclass twice ?
			AfxThrowNotSupportedException();
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
