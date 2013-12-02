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
    
    
    addAndMakeVisible(&analyserId);
    
    
    plotHeight = 150;
    plotY = 25;
    


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
    g.setColour (Colours::darkgrey);
    g.fillAll (Colours::silver);
    

    
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
    
    
    
    
    //g.setFont (15.0f);
    //g.drawFittedText (String(previousValue), 0, 0, getWidth(), getHeight(), Justification::centred, 1);

   // g.drawLine(10, 10, getWidth()-10, getHeight()-10);
}

//==============================================================================
void SoundAnalyserAudioProcessorEditor::resized()
{
    for (int i = 0;i < analysisComponents.size();i++)
    {
        analysisComponents[i]->setBounds(10,185+(i*analysisComponents[i]->getHeight()),analysisComponents[i]->getWidth(),analysisComponents[i]->getHeight());
    }
    
    newAnalysisButton.setBounds(10, getHeight()-100, 50, 50);
    
    analyserId.setBounds(300,getHeight()-60,40,18);
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
    if (analysisTree.getType() == AnalysisTypes::RMS)
    {
        analysisComponents.add(new SimpleAnalysisComponent(analysisTree));
    }
    else if (analysisTree.getType() == AnalysisTypes::PeakEnergy)
    {
        analysisComponents.add(new SimpleAnalysisComponent(analysisTree));
    }
    else if (analysisTree.getType() == AnalysisTypes::SpectralCentroid)
    {
        analysisComponents.add(new SimpleAnalysisComponent(analysisTree));
    }
    else if (analysisTree.getType() == AnalysisTypes::ZeroCrossingRate)
    {
        analysisComponents.add(new SimpleAnalysisComponent(analysisTree));
    }
    else if (analysisTree.getType() == AnalysisTypes::SpectralDifference)
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
