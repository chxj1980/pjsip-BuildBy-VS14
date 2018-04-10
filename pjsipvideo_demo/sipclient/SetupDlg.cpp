// SetupDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "sipclient.h"
#include "SetupDlg.h"

#include "Setting.h"

// CSetupDlg �Ի���

IMPLEMENT_DYNAMIC(CSetupDlg, CDialog)

CSetupDlg::CSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetupDlg::IDD, pParent)
{

}

CSetupDlg::~CSetupDlg()
{
}

void CSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboType);
}


BEGIN_MESSAGE_MAP(CSetupDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CSetupDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CSetupDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSetupDlg ��Ϣ�������

BOOL CSetupDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	path = CSetting::Instance().m_szIniPath;

	char buff[256];
	int len = 256;

	
	m_szUser = CSetting::Instance().m_szUser;
	m_szPW = CSetting::Instance().m_szPW;
	m_szServer = CSetting::Instance().m_szServer;

	//GetPrivateProfileString("setup","destUser", "1001", buff, len, path);
	//m_szDestUser = buff;
	m_szPort = CSetting::Instance().m_szPort;
	m_szPort2 = CSetting::Instance().m_szPort2;
	m_szAppType = CSetting::Instance().m_szAppType;

	GetDlgItem(IDC_EDIT_USER)->SetWindowTextA(m_szUser);
	GetDlgItem(IDC_EDIT_PW)->SetWindowTextA(m_szPW);
	GetDlgItem(IDC_EDIT_SERVER)->SetWindowTextA(m_szServer);
	//GetDlgItem(IDC_EDIT_USER2)->SetWindowTextA(m_szDestUser);
	//GetDlgItem(IDC_EDIT_USER4)->SetWindowTextA(m_szDestUser);
	GetDlgItem(IDC_EDIT_PORT)->SetWindowTextA(m_szPort);
	GetDlgItem(IDC_EDIT_PORT2)->SetWindowTextA(m_szPort2);

	m_comboType.AddString("���ſͻ���");
	m_comboType.AddString("sip����");

	if (m_szAppType == "0")
	{
		m_comboType.SetCurSel(0);
	}
	else
	{
		m_comboType.SetCurSel(1);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSetupDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT_USER)->GetWindowTextA(m_szUser);
	GetDlgItem(IDC_EDIT_PW)->GetWindowTextA(m_szPW);
	GetDlgItem(IDC_EDIT_SERVER)->GetWindowTextA(m_szServer);
	GetDlgItem(IDC_EDIT_PORT)->GetWindowTextA(m_szPort);
	GetDlgItem(IDC_EDIT_PORT2)->GetWindowTextA(m_szPort2);

	if (m_comboType.GetCurSel() == 0)
	{
		CSetting::Instance().m_szAppType = "0";
	}
	else
	{
		CSetting::Instance().m_szAppType = "1";
	}

	int ret = WritePrivateProfileString("setup", "localUser", m_szUser, path);
	ret = WritePrivateProfileString("setup", "pw", m_szPW, path);
	ret = WritePrivateProfileString("setup", "server", m_szServer, path);
	ret = WritePrivateProfileString("setup", "localPort", m_szPort, path);
	ret = WritePrivateProfileString("setup", "localVidioPort", m_szPort2, path);
	ret = WritePrivateProfileString("setup", "appType", CSetting::Instance().m_szAppType, path);

	CSetting::Instance().m_szUser = m_szUser;
	CSetting::Instance().m_szPW = m_szPW;
	CSetting::Instance().m_szServer = m_szServer;
	CSetting::Instance().m_szPort = m_szPort;
	CSetting::Instance().m_szPort2 = m_szPort2;

	

	OnOK();
}

void CSetupDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
