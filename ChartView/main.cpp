#include <wx/app.h>
#include <wx/event.h>
#include "ChartView.h"
#include "ElementPlotData.h"
#include <wx/image.h>

// Define the MainApp
class MainApp : public wxApp
{
public:
    MainApp() {}
    virtual ~MainApp() {}

    virtual bool OnInit() {
        // Add the common image handlers
        wxImage::AddHandler( new wxPNGHandler );
        wxImage::AddHandler( new wxJPEGHandler );
        
        wxLocale* locale = new wxLocale();
        locale->Init(locale->GetSystemLanguage(), wxLOCALE_LOAD_DEFAULT);
        
        // Exemplo
        std::vector<double> tempo;
        std::vector<double> curvaX;
        std::vector<double> curvaY;
        double sTempo = 0;
        for(int i = 0; i < 1000; ++i) {
            tempo.emplace_back(sTempo);
            curvaX.emplace_back(std::sin(sTempo));
            curvaY.emplace_back(std::cos(sTempo));
            sTempo += 0.01;
        }
        
        std::vector<ElementPlotData> plotDataList;
        
        ElementPlotData plotData;
        plotData.SetName(wxT("Teste"));
        plotData.SetCurveType(ElementPlotData::CurveType::CT_TEST);
        plotData.AddData(curvaX, wxT("Curva X"));
        plotData.AddData(curvaY, wxT("Curva Y"));
        plotDataList.push_back(plotData);
        
        // Para adicionar novos tipos de curva:
        // No arquivo "ElementPlotData.h", adicione um novo flag no enum CurveType. DEVE FICA ANTES DO FLAG "NUM_ELEMENTS". Exemplo CT_TESTE
        // Adicionar o novo tipo de curva no arquivo "ChartView.cpp", próximo da linha 108. Exemplo:
        //  rootElementName[static_cast<unsigned int>(ElementPlotData::CurveType::CT_TEST)] = wxT("Teste");

        ChartView* cView = new ChartView(nullptr, plotDataList, tempo);
        SetTopWindow(cView);
        cView->SetIcon(wxICON(aaaa));
        return GetTopWindow()->Show();
    }
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)
