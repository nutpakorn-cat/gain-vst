/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloworldGainAudioProcessorEditor::HelloworldGainAudioProcessorEditor (HelloworldGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(Slider::Rotary);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 20);
    gainSlider.setRange(0.0f, 1.0f, 0.01f);
    gainSlider.setValue(0.5f);
    gainSlider.addListener(this);

    addAndMakeVisible(gainSlider);
    setSize (400, 300);
}

HelloworldGainAudioProcessorEditor::~HelloworldGainAudioProcessorEditor()
{
}

//==============================================================================
void HelloworldGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(Colours::black);
}

void HelloworldGainAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 75, 100, 150);
}

void HelloworldGainAudioProcessorEditor::sliderValueChanged(Slider *slider) {
    if (slider == &gainSlider) {
        audioProcessor.gainSlider = gainSlider.getValue();
    }
}
