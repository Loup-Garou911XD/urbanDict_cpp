#include <wx/wx.h>
#include <curl/curl.h>
#include <iostream>
#include "urban_dict_request.h"

using namespace std;

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400)), // Initialize the base class and set size
          output_label(new wxStaticText(this, wxID_ANY, "Searching", wxPoint(10,100), wxDefaultSize)) { // Initialize output_label member variable
        
        // wxPanel* panel = new wxPanel(this, wxID_ANY);

        wxStaticText* text = new wxStaticText(this, wxID_ANY, "Hello, World!",
                                               wxPoint(10, 10), wxDefaultSize);

        wxButton* button = new wxButton(this, wxID_ANY, "Request", wxPoint(350 - 10, 10), wxSize(50, 50));
        button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
    }
    
    void OnButtonClick(wxCommandEvent& event) {
        int result = UrbanDictionaryRequest("hello");
        if (result == 0){
            output_label->SetLabel(wxString::Format(wxT("%d"), result));
        }
        else{
            output_label->SetLabel("Request failed");
        }
    }
private:
    wxStaticText* output_label; // Declare output_label member variable
};


class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MyFrame* frame = new MyFrame("window title");
        frame->Show(true);
        frame->Center();
        // frame->SetClientSize(400,400);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
