//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: codeformatterdlg.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "codeformatterdlgbase.h"
#include "formatoptions.h"
#include "PHPFormatterBuffer.h"


// Declare the bitmap loading function
extern void wxCrafterGgLOZbInitBitmapResources();

static bool bBitmapLoaded = false;


CodeFormatterBaseDlg::CodeFormatterBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterGgLOZbInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* bSizerMain = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(bSizerMain);
    
    m_splitterSettingsPreview = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(400,-1), wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME|wxSP_3DSASH);
    m_splitterSettingsPreview->SetSashGravity(0.5);
    m_splitterSettingsPreview->SetMinimumPaneSize(50);
    
    bSizerMain->Add(m_splitterSettingsPreview, 1, wxEXPAND, 5);
    
    m_panelSettings = new wxPanel(m_splitterSettingsPreview, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* bSizerSettings = new wxBoxSizer(wxVERTICAL);
    m_panelSettings->SetSizer(bSizerSettings);
    
    m_splitter16 = new wxSplitterWindow(m_panelSettings, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxSP_LIVE_UPDATE|wxSP_NO_XP_THEME|wxSP_3DSASH);
    m_splitter16->SetSashGravity(1);
    m_splitter16->SetMinimumPaneSize(100);
    
    bSizerSettings->Add(m_splitter16, 1, wxEXPAND, 5);
    
    m_splitterPage20 = new wxPanel(m_splitter16, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer26 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage20->SetSizer(boxSizer26);
    
    wxArrayString m_pgMgrArr;
    wxUnusedVar(m_pgMgrArr);
    wxArrayInt m_pgMgrIntArr;
    wxUnusedVar(m_pgMgrIntArr);
    m_pgMgr = new wxPropertyGridManager(m_splitterPage20, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxPG_DESCRIPTION|wxPG_SPLITTER_AUTO_CENTER);
    m_pgMgr->SetFocus();
    
    boxSizer26->Add(m_pgMgr, 1, wxALL|wxEXPAND, 5);
    
    m_pgPropGeneral = m_pgMgr->Append(  new wxPropertyCategory( _("General Options") ) );
    m_pgPropGeneral->SetHelpString(_("General Options"));
    
    m_pgPropAutoSave = m_pgMgr->AppendIn( m_pgPropGeneral,  new wxBoolProperty( _("Format file OnSave"), wxPG_LABEL, 0) );
    m_pgPropAutoSave->SetHelpString(_("Auto format the file before saving it"));
    
    m_pgPropCXX = m_pgMgr->Append(  new wxPropertyCategory( _("C++") ) );
    m_pgPropCXX->SetHelpString(_("C++ Related Settings"));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("AStyle"));
    m_pgMgrArr.Add(_("clang-format"));
    m_pgMgrIntArr.Add(kFormatEngineAStyle);
    m_pgMgrIntArr.Add(kFormatEngineClangFormat);
    m_pgPropEngine = m_pgMgr->AppendIn( m_pgPropCXX,  new wxEnumProperty( _("C++ Formatter Tool"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropEngine->SetHelpString(_("Select the formatter tool to use for the C,C++,Java and JavaScript language"));
    
    m_pgPropAstyleOptions = m_pgMgr->AppendIn( m_pgPropCXX,  new wxPropertyCategory( _("AStyle Options") ) );
    m_pgPropAstyleOptions->SetHelpString(wxT(""));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("GNU"));
    m_pgMgrArr.Add(_("Java"));
    m_pgMgrArr.Add(_("K&R"));
    m_pgMgrArr.Add(_("Linux"));
    m_pgMgrArr.Add(_("ANSI"));
    m_pgPropPreDefinedStyles = m_pgMgr->AppendIn( m_pgPropAstyleOptions,  new wxEnumProperty( _("PreDefined Styles"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropPreDefinedStyles->SetHelpString(_("Choose the formatting from one of the known styles"));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Break closing"));
    m_pgMgrArr.Add(_("Attach"));
    m_pgMgrArr.Add(_("Linux"));
    m_pgMgrArr.Add(_("Break"));
    m_pgMgrArr.Add(_("None"));
    m_pgPropBrackets = m_pgMgr->AppendIn( m_pgPropAstyleOptions,  new wxEnumProperty( _("Brackets"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropBrackets->SetHelpString(_("Bracket Style options define the bracket style to use"));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Class"));
    m_pgMgrArr.Add(_("Brackets"));
    m_pgMgrArr.Add(_("Switches"));
    m_pgMgrArr.Add(_("Namespaces"));
    m_pgMgrArr.Add(_("Case"));
    m_pgMgrArr.Add(_("Labels"));
    m_pgMgrArr.Add(_("Blocks"));
    m_pgMgrArr.Add(_("Preprocessors"));
    m_pgMgrArr.Add(_("Max Instatement Indent"));
    m_pgMgrArr.Add(_("Min Instatement Indent"));
    m_pgMgrIntArr.Add(AS_INDENT_CLASS);
    m_pgMgrIntArr.Add(AS_INDENT_BRACKETS);
    m_pgMgrIntArr.Add(AS_INDENT_SWITCHES);
    m_pgMgrIntArr.Add(AS_INDENT_NAMESPACES);
    m_pgMgrIntArr.Add(AS_INDENT_CASE);
    m_pgMgrIntArr.Add(AS_INDENT_LABELS);
    m_pgMgrIntArr.Add(AS_INDENT_BLOCKS);
    m_pgMgrIntArr.Add(AS_INDENT_PREPROCESSORS);
    m_pgMgrIntArr.Add(AS_MAX_INSTATEMENT_INDENT);
    m_pgMgrIntArr.Add(AS_MIN_COND_INDENT);
    m_pgPropIndentation = m_pgMgr->AppendIn( m_pgPropAstyleOptions,  new wxFlagsProperty( _("Indentation"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropIndentation->SetHelpString(wxT(""));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Break Blocks"));
    m_pgMgrArr.Add(_("Pad Parenthesis"));
    m_pgMgrArr.Add(_("Break Blocks All"));
    m_pgMgrArr.Add(_("Pad Parenthesis Outside"));
    m_pgMgrArr.Add(_("Break else-if"));
    m_pgMgrArr.Add(_("Pad Parenthesis Inside"));
    m_pgMgrArr.Add(_("Pad Operators"));
    m_pgMgrArr.Add(_("UnPad Parenthesis"));
    m_pgMgrArr.Add(_("One Line Keep Statement"));
    m_pgMgrArr.Add(_("Fill Empty Lines"));
    m_pgMgrArr.Add(_("One Line Keep Blocks"));
    m_pgMgrIntArr.Add(AS_BREAK_BLOCKS);
    m_pgMgrIntArr.Add(AS_PAD_PARENTHESIS);
    m_pgMgrIntArr.Add(AS_BREAK_BLOCKS_ALL);
    m_pgMgrIntArr.Add(AS_PAD_PARENTHESIS_OUT);
    m_pgMgrIntArr.Add(AS_BREAK_ELSEIF);
    m_pgMgrIntArr.Add(AS_PAD_PARENTHESIS_IN);
    m_pgMgrIntArr.Add(AS_PAD_OPER);
    m_pgMgrIntArr.Add(AS_UNPAD_PARENTHESIS);
    m_pgMgrIntArr.Add(AS_ONE_LINE_KEEP_STATEMENT);
    m_pgMgrIntArr.Add(AS_FILL_EMPTY_LINES);
    m_pgMgrIntArr.Add(AS_ONE_LINE_KEEP_BLOCKS);
    m_pgPropFormatting = m_pgMgr->AppendIn( m_pgPropAstyleOptions,  new wxFlagsProperty( _("Formatting"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropFormatting->SetHelpString(_("Select one or more formatting option from the list below"));
    
    m_pgPropClangFormat = m_pgMgr->AppendIn( m_pgPropCXX,  new wxPropertyCategory( _("ClangFormat Options") ) );
    m_pgPropClangFormat->SetHelpString(wxT(""));
    
    m_pgPropClangFormatExePath = m_pgMgr->AppendIn( m_pgPropClangFormat,  new wxFileProperty( _("clang-format path"), wxPG_LABEL, wxT("")) );
    m_pgMgr->SetPropertyAttribute(m_pgPropClangFormatExePath, wxPG_FILE_WILDCARD, wxT(""));
    m_pgPropClangFormatExePath->SetHelpString(_("Select the path to clang-format executable tool"));
    
    m_pgPropColumnLimit = m_pgMgr->AppendIn( m_pgPropClangFormat,  new wxIntProperty( _("Column Limit"), wxPG_LABEL, 0) );
    m_pgPropColumnLimit->SetHelpString(_("The column limit\nA column limit of 0 means that there is no column limit.\nIn this case, clang-format will respect the input's line breaking decisions within statements unless they contradict other rules"));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Linux"));
    m_pgMgrArr.Add(_("Attach"));
    m_pgMgrArr.Add(_("Stroustrup"));
    m_pgMgrArr.Add(_("Allman"));
    m_pgMgrArr.Add(_("GNU"));
    m_pgMgrIntArr.Add(kLinux);
    m_pgMgrIntArr.Add(kAttach);
    m_pgMgrIntArr.Add(kStroustrup);
    m_pgMgrIntArr.Add(kAllman);
    m_pgMgrIntArr.Add(kGNU);
    m_pgPropClangBraceBreakStyle = m_pgMgr->AppendIn( m_pgPropClangFormat,  new wxEnumProperty( _("Brace breaking style"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropClangBraceBreakStyle->SetHelpString(_("The brace breaking style to use."));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("LLVM"));
    m_pgMgrArr.Add(_("Google"));
    m_pgMgrArr.Add(_("WebKit"));
    m_pgMgrArr.Add(_("Chromium"));
    m_pgMgrArr.Add(_("Mozilla"));
    m_pgMgrIntArr.Add(kClangFormatLLVM);
    m_pgMgrIntArr.Add(kClangFormatGoogle);
    m_pgMgrIntArr.Add(kClangFormatWebKit);
    m_pgMgrIntArr.Add(kClangFormatChromium);
    m_pgMgrIntArr.Add(kClangFormatMozilla);
    m_pgPropClangFormatStyle = m_pgMgr->AppendIn( m_pgPropClangFormat,  new wxEnumProperty( _("Style"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropClangFormatStyle->SetHelpString(_("Coding style"));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Align Escaped Newlines Left"));
    m_pgMgrArr.Add(_("Align Trailing Comments"));
    m_pgMgrArr.Add(_("Allow All Parameters Of Declaration On Next Line"));
    m_pgMgrArr.Add(_("Allow Short Functions On A Single Line"));
    m_pgMgrArr.Add(_("Allow Short Blocks On A Single Line"));
    m_pgMgrArr.Add(_("Allow Short Loops On A Single Line"));
    m_pgMgrArr.Add(_("Allow Short If Statements On A SingleLine"));
    m_pgMgrArr.Add(_("Always Break Before Multiline Strings"));
    m_pgMgrArr.Add(_("Always Break Template Declarations"));
    m_pgMgrArr.Add(_("Bin Pack Parameters"));
    m_pgMgrArr.Add(_("Break Before Binary Operators"));
    m_pgMgrArr.Add(_("Break Before Ternary Operators"));
    m_pgMgrArr.Add(_("Break Constructor Initializers Before Comma"));
    m_pgMgrArr.Add(_("Indent Case Labels"));
    m_pgMgrArr.Add(_("Indent Function DeclarationAfterType"));
    m_pgMgrArr.Add(_("Space Before Assignment Operators"));
    m_pgMgrArr.Add(_("Space Before Parentheses"));
    m_pgMgrArr.Add(_("Spaces In Parentheses"));
    m_pgMgrArr.Add(_("Pointer And Reference Aligned to the Right"));
    m_pgMgrIntArr.Add(kAlignEscapedNewlinesLeft);
    m_pgMgrIntArr.Add(kAlignTrailingComments);
    m_pgMgrIntArr.Add(kAllowAllParametersOfDeclarationOnNextLine);
    m_pgMgrIntArr.Add(kAllowShortFunctionsOnASingleLine);
    m_pgMgrIntArr.Add(kAllowShortBlocksOnASingleLine);
    m_pgMgrIntArr.Add(kAllowShortLoopsOnASingleLine);
    m_pgMgrIntArr.Add(kAllowShortIfStatementsOnASingleLine);
    m_pgMgrIntArr.Add(kAlwaysBreakBeforeMultilineStrings);
    m_pgMgrIntArr.Add(kAlwaysBreakTemplateDeclarations);
    m_pgMgrIntArr.Add(kBinPackParameters);
    m_pgMgrIntArr.Add(kBreakBeforeBinaryOperators);
    m_pgMgrIntArr.Add(kBreakBeforeTernaryOperators);
    m_pgMgrIntArr.Add(kBreakConstructorInitializersBeforeComma);
    m_pgMgrIntArr.Add(kIndentCaseLabels);
    m_pgMgrIntArr.Add(kIndentFunctionDeclarationAfterType);
    m_pgMgrIntArr.Add(kSpaceBeforeAssignmentOperators);
    m_pgMgrIntArr.Add(kSpaceBeforeParens);
    m_pgMgrIntArr.Add(kSpacesInParentheses);
    m_pgMgrIntArr.Add(kPointerAlignmentRight);
    m_pgPropClangFormattingOptions = m_pgMgr->AppendIn( m_pgPropClangFormat,  new wxFlagsProperty( _("Clang Formatting Options"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropClangFormattingOptions->SetHelpString(wxT(""));
    
    m_pgPropPhpFormatter = m_pgMgr->Append(  new wxPropertyCategory( _("PHP") ) );
    m_pgPropPhpFormatter->SetHelpString(_("PHP related settings"));
    
    m_pgMgrArr.Clear();
    m_pgMgrIntArr.Clear();
    m_pgMgrArr.Add(_("Break before class"));
    m_pgMgrArr.Add(_("Break before function"));
    m_pgMgrArr.Add(_("Break before 'while'"));
    m_pgMgrArr.Add(_("Break before 'foreach'"));
    m_pgMgrArr.Add(_("'else' doesn't break"));
    m_pgMgrArr.Add(_("Break after 'heredoc' statement"));
    m_pgMgrIntArr.Add(kPFF_BreakBeforeClass);
    m_pgMgrIntArr.Add(kPFF_BreakBeforeFunction);
    m_pgMgrIntArr.Add(kPFF_BreakBeforeWhile);
    m_pgMgrIntArr.Add(kPFF_BreakBeforeForeach);
    m_pgMgrIntArr.Add(kPFF_ElseOnSameLineAsClosingCurlyBrace);
    m_pgMgrIntArr.Add(kPFF_BreakAfterHeredoc);
    m_pgPropPhpFormatterOptions = m_pgMgr->AppendIn( m_pgPropPhpFormatter,  new wxFlagsProperty( _("PHPFormatter Options"), wxPG_LABEL, m_pgMgrArr, m_pgMgrIntArr, 0) );
    m_pgPropPhpFormatterOptions->SetHelpString(wxT(""));
    
    m_splitterPage24 = new wxPanel(m_splitter16, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitter16->SplitHorizontally(m_splitterPage20, m_splitterPage24, 0);
    
    wxBoxSizer* boxSizer28 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage24->SetSizer(boxSizer28);
    
    wxBoxSizer* bCustomSettingsSizer = new wxBoxSizer(wxVERTICAL);
    
    boxSizer28->Add(bCustomSettingsSizer, 1, wxEXPAND, 0);
    
    wxBoxSizer* boxSizer57 = new wxBoxSizer(wxHORIZONTAL);
    
    bCustomSettingsSizer->Add(boxSizer57, 0, wxEXPAND, 5);
    
    m_staticText59 = new wxStaticText(m_splitterPage24, wxID_ANY, _("AStyle Only:"), wxDefaultPosition, wxSize(-1,-1), 0);
    wxFont m_staticText59Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_staticText59Font.SetWeight(wxFONTWEIGHT_BOLD);
    m_staticText59->SetFont(m_staticText59Font);
    
    boxSizer57->Add(m_staticText59, 0, wxALL, 5);
    
    m_staticText3 = new wxStaticText(m_splitterPage24, wxID_ANY, _("Custom user settings"), wxDefaultPosition, wxSize(-1, -1), 0);
    
    boxSizer57->Add(m_staticText3, 0, wxALL, 5);
    
    m_textCtrlUserFlags = new wxTextCtrl(m_splitterPage24, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1, -1), wxTE_RICH2|wxTE_PROCESS_TAB|wxTE_PROCESS_ENTER|wxTE_MULTILINE);
    wxFont m_textCtrlUserFlagsFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans"));
    m_textCtrlUserFlags->SetFont(m_textCtrlUserFlagsFont);
    
    bCustomSettingsSizer->Add(m_textCtrlUserFlags, 1, wxALL|wxEXPAND, 5);
    
    m_panelPreview = new wxPanel(m_splitterSettingsPreview, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitterSettingsPreview->SplitVertically(m_panelSettings, m_panelPreview, 0);
    
    wxBoxSizer* bPreviewSizer = new wxBoxSizer(wxHORIZONTAL);
    m_panelPreview->SetSizer(bPreviewSizer);
    
    m_notebook65 = new wxNotebook(m_panelPreview, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    
    bPreviewSizer->Add(m_notebook65, 1, wxALL|wxEXPAND, 5);
    
    m_panel67 = new wxPanel(m_notebook65, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook65->AddPage(m_panel67, _("C++ Preview"), false);
    
    wxBoxSizer* boxSizer71 = new wxBoxSizer(wxVERTICAL);
    m_panel67->SetSizer(boxSizer71);
    
    m_textCtrlPreview = new wxStyledTextCtrl(m_panel67, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    // Configure the fold margin
    m_textCtrlPreview->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_textCtrlPreview->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_textCtrlPreview->SetMarginSensitive(4, true);
    m_textCtrlPreview->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_textCtrlPreview->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_textCtrlPreview->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_textCtrlPreview->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_textCtrlPreview->SetMarginWidth(2, 0);
    m_textCtrlPreview->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_textCtrlPreview->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_textCtrlPreview->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_textCtrlPreview->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_textCtrlPreview->SetMarginMask(3, 0);
    m_textCtrlPreview->SetMarginWidth(3,0);
    // Select the lexer
    m_textCtrlPreview->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_textCtrlPreview->StyleClearAll();
    m_textCtrlPreview->SetWrapMode(0);
    m_textCtrlPreview->SetIndentationGuides(0);
    m_textCtrlPreview->SetKeyWords(0, wxT(""));
    m_textCtrlPreview->SetKeyWords(1, wxT(""));
    m_textCtrlPreview->SetKeyWords(2, wxT(""));
    m_textCtrlPreview->SetKeyWords(3, wxT(""));
    m_textCtrlPreview->SetKeyWords(4, wxT(""));
    
    boxSizer71->Add(m_textCtrlPreview, 1, wxALL|wxEXPAND, 5);
    
    m_panel69 = new wxPanel(m_notebook65, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook65->AddPage(m_panel69, _("PHP Preview"), false);
    
    wxBoxSizer* boxSizer73 = new wxBoxSizer(wxVERTICAL);
    m_panel69->SetSizer(boxSizer73);
    
    m_stcPhpPreview = new wxStyledTextCtrl(m_panel69, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    // Configure the fold margin
    m_stcPhpPreview->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcPhpPreview->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcPhpPreview->SetMarginSensitive(4, true);
    m_stcPhpPreview->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcPhpPreview->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcPhpPreview->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcPhpPreview->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcPhpPreview->SetMarginWidth(2, 0);
    m_stcPhpPreview->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcPhpPreview->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcPhpPreview->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcPhpPreview->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcPhpPreview->SetMarginMask(3, 0);
    m_stcPhpPreview->SetMarginWidth(3,0);
    // Select the lexer
    m_stcPhpPreview->SetLexer(wxSTC_LEX_HTML);
    // Set default font / styles
    m_stcPhpPreview->StyleClearAll();
    m_stcPhpPreview->SetWrapMode(0);
    m_stcPhpPreview->SetIndentationGuides(0);
    m_stcPhpPreview->SetKeyWords(0, wxT(""));
    m_stcPhpPreview->SetKeyWords(1, wxT(""));
    m_stcPhpPreview->SetKeyWords(2, wxT(""));
    m_stcPhpPreview->SetKeyWords(3, wxT(""));
    m_stcPhpPreview->SetKeyWords(4, wxT(""));
    
    boxSizer73->Add(m_stcPhpPreview, 1, wxALL|wxEXPAND, 5);
    
    wxBoxSizer* bSizerButtons = new wxBoxSizer(wxHORIZONTAL);
    
    bSizerMain->Add(bSizerButtons, 0, wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_stdBtnSizer30 = new wxStdDialogButtonSizer();
    
    bSizerButtons->Add(m_stdBtnSizer30, 0, wxALL, 5);
    
    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer30->AddButton(m_buttonOK);
    
    m_buttonApply = new wxButton(this, wxID_APPLY, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer30->AddButton(m_buttonApply);
    
    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer30->AddButton(m_buttonCancel);
    
    m_buttonHelp = new wxButton(this, wxID_HELP, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer30->AddButton(m_buttonHelp);
    m_stdBtnSizer30->Realize();
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_pgMgr->Connect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(CodeFormatterBaseDlg::OnAStylePropertyChanged), NULL, this);
    m_textCtrlUserFlags->Connect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(CodeFormatterBaseDlg::OnCustomAstyleFlags), NULL, this);
    m_buttonOK->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CodeFormatterBaseDlg::OnOK), NULL, this);
    m_buttonApply->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CodeFormatterBaseDlg::OnApplyUI), NULL, this);
    m_buttonApply->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CodeFormatterBaseDlg::OnApply), NULL, this);
    m_buttonHelp->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CodeFormatterBaseDlg::OnHelp), NULL, this);
    
}

CodeFormatterBaseDlg::~CodeFormatterBaseDlg()
{
    m_pgMgr->Disconnect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(CodeFormatterBaseDlg::OnAStylePropertyChanged), NULL, this);
    m_textCtrlUserFlags->Disconnect(wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler(CodeFormatterBaseDlg::OnCustomAstyleFlags), NULL, this);
    m_buttonOK->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CodeFormatterBaseDlg::OnOK), NULL, this);
    m_buttonApply->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(CodeFormatterBaseDlg::OnApplyUI), NULL, this);
    m_buttonApply->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CodeFormatterBaseDlg::OnApply), NULL, this);
    m_buttonHelp->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CodeFormatterBaseDlg::OnHelp), NULL, this);
    
}
