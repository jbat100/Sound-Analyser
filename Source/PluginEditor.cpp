/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SoundAnalyserAudioProcessorEditor::SoundAnalyserAudioProcessorEditor (SoundAnalyserAudioProcessor* ownerFilter,  ValueTree analyserTree_)
    : AudioProcessorEditor (ownerFilter), analyserTree(analyserTree_)
{
    // This is where our plugin's editor size is set.
    setSize (600, 500);
    

    
    newAnalysisButton.setButtonText("+");
    addAndMakeVisible(&newAnalysisButton);
    newAnalysisButton.addListener(this);
    
    
    
    //analyserId.setText(analyserTree[AnalysisModel::Ids::AnalyserId], dontSendNotification);
//    analyserId.setEditable(true);
  //  analyserId.setColour(Label::ColourIds::backgroundColourId, Colours::white);
   // analyserId.setColour(Label::ColourIds::outlineColourId, Colours::lightgrey);
    analyserId.addItem("1", 1);
    analyserId.addItem("2", 2);
    analyserId.addItem("3", 3);
    analyserId.addItem("4", 4);
    analyserId.addItem("5", 5);
    analyserId.addItem("6", 6);
    analyserId.addItem("7", 7);
    
    
    bufferSizeLabel.setText(String("Buffer Size: " + analyserTree[AnalysisModel::Ids::BufferSize].toString()), dontSendNotification);
    addAndMakeVisible(&bufferSizeLabel);
    
    addAndMakeVisible(&analyserId);
    
    
    analyserIdText.setText("Analyser Id:", dontSendNotification);
    addAndMakeVisible(&analyserIdText);
    
    
    plotHeight = 150;
    plotY = 40;
    


    analyserTree.addListener(this);
    
    analyserId.addListener(this);
    
    refreshFromTree();
    
    DBG("GUI CONSTRUCTOR CALLED");
    
    startTimer (50);
}



//==============================================================================
SoundAnalyserAudioProcessorEditor::~SoundAnalyserAudioProcessorEditor()
{
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::paint (Graphics& g)
{
    // FIX!!!!!! - DO WE HAVE A THREADING PROBLEM HERE?
    // WHAT IF THE PROCESSOR IS WRITING TO THE PLOT HISTORY OR VECTOR?
    // DOESN'T SEEM TO HAPPEN BUT NEED TO MAKE SURE PERHAPS?
    
    g.setColour (Colours::darkgrey);
    g.fillAll (Colours::silver);
    
    if (getProcessor()->analyser.currentAnalysisToPlotType == FloatOutput)
    {
        int N = getProcessor()->analyser.plotHistory.size();
        
        int plotX = (getWidth()- N)/2;
        
        
        g.fillRect(plotX, plotY, N, plotHeight);
        
        g.setColour(Colours::lightsteelblue);

        float previousValue = getProcessor()->analyser.plotHistory[0];
        
        // get the max value
        float maxValue = -10000;
        for (int i = 0;i < N;i++)
        {
            if (getProcessor()->analyser.plotHistory[i] > maxValue)
            {
                maxValue = getProcessor()->analyser.plotHistory[i];
            }
        }
        
        // do the plotting
        for (int i = 0;i < N-1;i++)
        {
            float currentValue = getProcessor()->analyser.plotHistory[i+1];
            
            int p1 = plotY + (plotHeight - ((previousValue/maxValue)*plotHeight));
            int p2 = plotY + (plotHeight - ((currentValue/maxValue)*plotHeight));
            
            g.drawLine(plotX+i,p1,plotX+i+1,p2);
            previousValue = currentValue;
        }
    
    }
    else if (getProcessor()->analyser.currentAnalysisToPlotType == VectorOutput)
    {
        int N = getProcessor()->analyser.vectorPlot.size();
        int plotWidth = 512;
        
        //int plotX = (getWidth()- N)/2;
        int plotX = (getWidth() - plotWidth) / 2;
        
        
        //g.fillRect(plotX, plotY, N, plotHeight);
        g.fillRect(plotX,plotY, plotWidth,plotHeight);
        
        g.setColour(Colours::greenyellow);
        
        float previousValue = getProcessor()->analyser.vectorPlot[0];
        
        // get the max value
        float maxValue = -10000;
        for (int i = 0;i < N;i++)
        {
            if (getProcessor()->analyser.vectorPlot[i] > maxValue)
            {
                maxValue = getProcessor()->analyser.vectorPlot[i];
            }
        }
        
        // do the plotting
        for (int i = 0;i < N-1;i++)
        {
            float currentValue = getProcessor()->analyser.vectorPlot[i+1];
            
            int p1 = plotY + (plotHeight - ((previousValue/maxValue)*plotHeight));
            int p2 = plotY + (plotHeight - ((currentValue/maxValue)*plotHeight));
            
            int x1 = i*round(512.0/((double)N-1.));
            int x2 = (i+1)*round(512.0/((double)N-1.));
            
            g.drawLine(plotX+x1,p1,plotX+x2,p2);
            //g.drawLine(plotX+i,p1,plotX+i+1,p2);

            previousValue = currentValue;
        }
        
    }
    
    
    //g.setFont (15.0f);
    //g.drawFittedText (String(previousValue), 0, 0, getWidth(), getHeight(), Justification::centred, 1);

   // g.drawLine(10, 10, getWidth()-10, getHeight()-10);
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::resized()
{
    bufferSizeLabel.setBounds(10, 10, 120, 20);
    
    int lastComponentY = 0;
    
    for (int i = 0;i < analysisComponents.size();i++)
    {
        analysisComponents[i]->setBounds(10,(plotY+plotHeight+10)+lastComponentY,analysisComponents[i]->getWidth(),analysisComponents[i]->getHeight());
        
        lastComponentY += analysisComponents[i]->getHeight();
    }
    
    newAnalysisButton.setBounds(10, getHeight()-60, 50, 50);
    
    analyserIdText.setBounds(getWidth()-160, 10, 80, 20);
    analyserId.setBounds(getWidth()-70, 10, 60, 20);
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::timerCallback()
{
    repaint();
}


//==============================================================================
void SoundAnalyserAudioProcessorEditor::buttonClicked (Button* button)
{    
    if (button == &newAnalysisButton)
    {
        AlertWindow w ("Add new analysis..",
                       "Please slect a new device from the list below",
                       AlertWindow::NoIcon);
        
        StringArray options = AnalysisModel::getAllAnalysisNames();
        
//        for (int i = 0;i < Analyses::NumAnalyses;i++)
//        {
//            options.add(AnalysisModel::getAnalysisName(i));
//        }
        

        
        w.addComboBox ("option", options, "some options");
        
        w.addButton ("ok",     1, KeyPress (KeyPress::returnKey, 0, 0));
        w.addButton ("cancel", 0, KeyPress (KeyPress::escapeKey, 0, 0));
        
        if (w.runModalLoop() != 0) // is they picked 'ok'
        {
            // this is the item they chose in the drop-down list..
            const int optionIndexChosen = w.getComboBoxComponent ("option")->getSelectedItemIndex();
            

            
            AnalysisModel::addNewAnalysis(analyserTree,optionIndexChosen);
        }
    }
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::addAnalysis(ValueTree& analysisTree)
{
    // FFT
    if (analysisTree.getType() == AnalysisTypes::FFT)
    {
        analysisComponents.add(new FFTComponent(analysisTree));
    }
    else // GENERIC
    {
        analysisComponents.add(new SimpleAnalysisComponent(analysisTree));
    }
    
    
    addChildComponent(analysisComponents.getLast());
    analysisComponents.getLast()->setVisible(true);
    
    resized();
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
    if (property == AnalysisModel::Ids::AnalyserId)
    {
        refreshFromTree();
    }
    else if (property == AnalysisModel::Ids::BufferSize)
    {
        bufferSizeLabel.setText(String("Buffer Size: " + analyserTree[AnalysisModel::Ids::BufferSize].toString()), dontSendNotification);
    }
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::valueTreeChildAdded (ValueTree& parentTree, ValueTree& childWhichHasBeenAdded)
{
    addAnalysis(childWhichHasBeenAdded);
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::valueTreeChildRemoved (ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved)
{
    refreshFromTree();
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::valueTreeChildOrderChanged (ValueTree& parentTreeWhoseChildrenHaveMoved)
{
    
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::valueTreeParentChanged (ValueTree& treeWhoseParentHasChanged)
{
    
}
