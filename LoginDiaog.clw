; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDiaogDlg
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LoginDiaog.h"

ClassCount=4
Class1=CLoginDiaogApp
Class2=CLoginDiaogDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CLoginEdit
Resource3=IDD_LOGINDIAOG_DIALOG

[CLS:CLoginDiaogApp]
Type=0
HeaderFile=LoginDiaog.h
ImplementationFile=LoginDiaog.cpp
Filter=N

[CLS:CLoginDiaogDlg]
Type=0
HeaderFile=LoginDiaogDlg.h
ImplementationFile=LoginDiaogDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CLoginDiaogDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=LoginDiaogDlg.h
ImplementationFile=LoginDiaogDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LOGINDIAOG_DIALOG]
Type=1
Class=CLoginDiaogDlg
ControlCount=2
Control1=IDC_EDIT_USER,edit,1350631552
Control2=IDC_EDIT_PASSWORD,edit,1350631552

[CLS:CLoginEdit]
Type=0
HeaderFile=LoginEdit.h
ImplementationFile=LoginEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC
LastObject=CLoginEdit

