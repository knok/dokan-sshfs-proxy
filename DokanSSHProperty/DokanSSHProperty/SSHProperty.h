// SSHProperty.h : CSSHProperty �̐錾

#pragma once
#include "resource.h"       // ���C�� �V���{��
#include <string>
#include <list>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "DCOM �̊��S�T�|�[�g���܂�ł��Ȃ� Windows Mobile �v���b�g�t�H�[���̂悤�� Windows CE �v���b�g�t�H�[���ł́A�P��X���b�h COM �I�u�W�F�N�g�͐������T�|�[�g����Ă��܂���BATL ���P��X���b�h COM �I�u�W�F�N�g�̍쐬���T�|�[�g���邱�ƁA����т��̒P��X���b�h COM �I�u�W�F�N�g�̎����̎g�p�������邱�Ƃ���������ɂ́A_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ���`���Ă��������B���g�p�� rgs �t�@�C���̃X���b�h ���f���� 'Free' �ɐݒ肳��Ă���ADCOM Windows CE �ȊO�̃v���b�g�t�H�[���ŃT�|�[�g�����B��̃X���b�h ���f���Ɛݒ肳��Ă��܂����B"
#endif


// CSSHProperty

class ATL_NO_VTABLE CSSHProperty :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSSHProperty, &CLSID_SSHProperty>,
	public IShellExtInit,
	public IShellPropSheetExt
{
public:
	CSSHProperty()
	{
	}


DECLARE_REGISTRY_RESOURCEID(IDR_SSHPROPERTY)

DECLARE_NOT_AGGREGATABLE(CSSHProperty)

BEGIN_COM_MAP(CSSHProperty)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IShellPropSheetExt)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	typedef std::list< std::wstring > string_list;
 
public:


    // IShellExtInit
    STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IShellPropSheetExt
    STDMETHODIMP AddPages(LPFNADDPROPSHEETPAGE, LPARAM);
    STDMETHODIMP ReplacePage(UINT, LPFNADDPROPSHEETPAGE, LPARAM) { return E_NOTIMPL; }

protected:
	string_list m_lsFiles;

};

OBJECT_ENTRY_AUTO(__uuidof(SSHProperty), CSSHProperty)
