// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

#include "stdafx.h"
#include "mcsdsc.h"

/////////////////////////////////////////////////////////////////////////////
// CMcsDsc

IMPLEMENT_DYNCREATE(CMcsDsc, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CMcsDsc properties

CString CMcsDsc::GetSql()
{
	CString result;
	GetProperty(0x2, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetSql(LPCTSTR propVal)
{
	SetProperty(0x2, VT_BSTR, propVal);
}

long CMcsDsc::GetLoginTimeout()
{
	long result;
	GetProperty(0x3, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetLoginTimeout(long propVal)
{
	SetProperty(0x3, VT_I4, propVal);
}

CString CMcsDsc::GetVersion()
{
	CString result;
	GetProperty(0x4, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetVersion(LPCTSTR propVal)
{
	SetProperty(0x4, VT_BSTR, propVal);
}

CString CMcsDsc::GetConnect()
{
	CString result;
	GetProperty(0x5, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetConnect(LPCTSTR propVal)
{
	SetProperty(0x5, VT_BSTR, propVal);
}

long CMcsDsc::GetQueryTimeout()
{
	long result;
	GetProperty(0x6, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetQueryTimeout(long propVal)
{
	SetProperty(0x6, VT_I4, propVal);
}

long CMcsDsc::GetRowsetSize()
{
	long result;
	GetProperty(0x7, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetRowsetSize(long propVal)
{
	SetProperty(0x7, VT_I4, propVal);
}

long CMcsDsc::GetResultsetType()
{
	long result;
	GetProperty(0x8, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetResultsetType(long propVal)
{
	SetProperty(0x8, VT_I4, propVal);
}

long CMcsDsc::GetMaxRows()
{
	long result;
	GetProperty(0x9, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetMaxRows(long propVal)
{
	SetProperty(0x9, VT_I4, propVal);
}

CString CMcsDsc::GetLogMessages()
{
	CString result;
	GetProperty(0xa, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetLogMessages(LPCTSTR propVal)
{
	SetProperty(0xa, VT_BSTR, propVal);
}

long CMcsDsc::GetKeysetSize()
{
	long result;
	GetProperty(0xb, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetKeysetSize(long propVal)
{
	SetProperty(0xb, VT_I4, propVal);
}

CString CMcsDsc::GetCaption()
{
	CString result;
	GetProperty(DISPID_CAPTION, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetCaption(LPCTSTR propVal)
{
	SetProperty(DISPID_CAPTION, VT_BSTR, propVal);
}

OLE_COLOR CMcsDsc::GetBackColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_BACKCOLOR, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetBackColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_BACKCOLOR, VT_I4, propVal);
}

OLE_COLOR CMcsDsc::GetForeColor()
{
	OLE_COLOR result;
	GetProperty(DISPID_FORECOLOR, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetForeColor(OLE_COLOR propVal)
{
	SetProperty(DISPID_FORECOLOR, VT_I4, propVal);
}

CString CMcsDsc::GetDataSourceName()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetDataSourceName(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

short CMcsDsc::GetEditMode()
{
	short result;
	GetProperty(0xc, VT_I2, (void*)&result);
	return result;
}

void CMcsDsc::SetEditMode(short propVal)
{
	SetProperty(0xc, VT_I2, propVal);
}

BOOL CMcsDsc::GetEnabled()
{
	BOOL result;
	GetProperty(DISPID_ENABLED, VT_BOOL, (void*)&result);
	return result;
}

void CMcsDsc::SetEnabled(BOOL propVal)
{
	SetProperty(DISPID_ENABLED, VT_BOOL, propVal);
}

LPDISPATCH CMcsDsc::GetResultset()
{
	LPDISPATCH result;
	GetProperty(0xd, VT_DISPATCH, (void*)&result);
	return result;
}

void CMcsDsc::SetResultset(LPDISPATCH propVal)
{
	SetProperty(0xd, VT_DISPATCH, propVal);
}

BOOL CMcsDsc::GetReadOnly()
{
	BOOL result;
	GetProperty(0xe, VT_BOOL, (void*)&result);
	return result;
}

void CMcsDsc::SetReadOnly(BOOL propVal)
{
	SetProperty(0xe, VT_BOOL, propVal);
}

short CMcsDsc::GetOptions()
{
	short result;
	GetProperty(0xf, VT_I2, (void*)&result);
	return result;
}

void CMcsDsc::SetOptions(short propVal)
{
	SetProperty(0xf, VT_I2, propVal);
}

CString CMcsDsc::GetUserName()
{
	CString result;
	GetProperty(0x10, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetUserName(LPCTSTR propVal)
{
	SetProperty(0x10, VT_BSTR, propVal);
}

CString CMcsDsc::GetPassword()
{
	CString result;
	GetProperty(0x11, VT_BSTR, (void*)&result);
	return result;
}

void CMcsDsc::SetPassword(LPCTSTR propVal)
{
	SetProperty(0x11, VT_BSTR, propVal);
}

long CMcsDsc::GetCursorDriver()
{
	long result;
	GetProperty(0x12, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetCursorDriver(long propVal)
{
	SetProperty(0x12, VT_I4, propVal);
}

LPFONTDISP CMcsDsc::GetFont()
{
	LPFONTDISP result;
	GetProperty(DISPID_FONT, VT_DISPATCH, (void*)&result);
	return result;
}

void CMcsDsc::SetFont(LPFONTDISP propVal)
{
	SetProperty(DISPID_FONT, VT_DISPATCH, propVal);
}

LPDISPATCH CMcsDsc::GetConnection()
{
	LPDISPATCH result;
	GetProperty(0x13, VT_DISPATCH, (void*)&result);
	return result;
}

void CMcsDsc::SetConnection(LPDISPATCH propVal)
{
	SetProperty(0x13, VT_DISPATCH, propVal);
}

long CMcsDsc::GetEOFAction()
{
	long result;
	GetProperty(0x14, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetEOFAction(long propVal)
{
	SetProperty(0x14, VT_I4, propVal);
}

long CMcsDsc::GetBOFAction()
{
	long result;
	GetProperty(0x15, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetBOFAction(long propVal)
{
	SetProperty(0x15, VT_I4, propVal);
}

long CMcsDsc::GetErrorThreshold()
{
	long result;
	GetProperty(0x16, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetErrorThreshold(long propVal)
{
	SetProperty(0x16, VT_I4, propVal);
}

long CMcsDsc::GetLockType()
{
	long result;
	GetProperty(0x19, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetLockType(long propVal)
{
	SetProperty(0x19, VT_I4, propVal);
}

long CMcsDsc::GetPrompt()
{
	long result;
	GetProperty(0x1a, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetPrompt(long propVal)
{
	SetProperty(0x1a, VT_I4, propVal);
}

BOOL CMcsDsc::GetTransactions()
{
	BOOL result;
	GetProperty(0x1e, VT_BOOL, (void*)&result);
	return result;
}

void CMcsDsc::SetTransactions(BOOL propVal)
{
	SetProperty(0x1e, VT_BOOL, propVal);
}

long CMcsDsc::GetAppearance()
{
	long result;
	GetProperty(0x1f, VT_I4, (void*)&result);
	return result;
}

void CMcsDsc::SetAppearance(long propVal)
{
	SetProperty(0x1f, VT_I4, propVal);
}

LPDISPATCH CMcsDsc::GetEnvironment()
{
	LPDISPATCH result;
	GetProperty(0x20, VT_DISPATCH, (void*)&result);
	return result;
}

void CMcsDsc::SetEnvironment(LPDISPATCH propVal)
{
	SetProperty(0x20, VT_DISPATCH, propVal);
}

BOOL CMcsDsc::GetStillExecuting()
{
	BOOL result;
	GetProperty(0x21, VT_BOOL, (void*)&result);
	return result;
}

void CMcsDsc::SetStillExecuting(BOOL propVal)
{
	SetProperty(0x21, VT_BOOL, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CMcsDsc operations

void CMcsDsc::Refresh()
{
	InvokeHelper(DISPID_REFRESH, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::UpdateControls()
{
	InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::UpdateRow()
{
	InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::BeginTrans()
{
	InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::CommitTrans()
{
	InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::RollbackTrans()
{
	InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::Cancel()
{
	InvokeHelper(0x22, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CMcsDsc::AboutBox()
{
	InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
