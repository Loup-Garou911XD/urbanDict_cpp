#include <wx/wx.h>
#include <curl/curl.h>
#include <iostream>
#include "urban_dict_request.h"
#include <json/json.h>

using namespace std;

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString &title)
        : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize), // Initialize the base class and set size
          output_label(new wxStaticText(this, wxID_ANY, "Searching", wxPoint(10,100), wxDefaultSize)) { // Initialize output_label member variable
        
        // wxPanel* panel = new wxPanel(this, wxID_ANY);

        wxStaticText* text = new wxStaticText(this, wxID_ANY, "Hello, World!",
                                               wxPoint(10, 10), wxDefaultSize);

        wxButton* button = new wxButton(this, wxID_ANY, "Request", wxPoint(350 - 10, 10), wxSize(50, 50));
        button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
    }
    
    void OnButtonClick(wxCommandEvent& event) {
        string result = UrbanDictionaryRequest("hello");
        if (result != "NA"){
            Json::Value data;
            Json::Reader reader;
            wxString label;
            bool parsing_successfull = reader.parse(result.c_str(), data);
            if ( !parsing_successfull ){
                cout  << "Failed to parse" << reader.getFormattedErrorMessages();    
                // label = wxString::FromUTF8("Err converting to json");
            }
            else{
                data = data.get("list","woompwoomp");
                // cout << data << endl;
                if (data.size() > 0) {
                    data = data[0]["definition"];
                    label = wxString::FromUTF8(data.asString().c_str());
                }
                // label = wxString::FromUTF8(data.get("list", "woompwoomp").asString().c_str());
            }
            output_label->SetLabel(label);
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
