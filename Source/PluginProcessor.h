/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

/*
 Welcome to this Project 10 Prerequisite project!
 
 The purpose of this project is to prove that you possess the
 necessary command of the C++ language to complete PFM::C++ Project 10
 without needing any help regarding the language.
 
 Feel free to use the Standalone Build Target as your means of testing.
 There is no need to run this inside your DAW as a VST but you
 can if you want to and know how.

 Instructions have also been provided in processBlock()
 =================================================================
 This project is purposely broken.
 
 Your job is to
    - clear the compiler errors
    - make it produce a sine wave tone at 440hz @ -12dbFS.
 
 Your challenge will be in writing a custom class
 that will be used by the oscillator producing the sinewave.
 
 the Oscillator you will be using has already been added as a
 member variable at the end of the Project10PrereqAudioProcessor
 
 I have provided you with a starting template below for this custom class.
 */

#include <JuceHeader.h>

template<typename T>
struct Data
{
    using value_type = T;
    
    Data(T d)
    {
        data = d;
    }
    
    T operator * (const T& other)
    {
        return data * other;
    }
    
    T operator + (const T& other)
    {
        return data + other;
    }
    
    operator float()
    {
        return data;
    }
    
private:
    T data;
};

//==============================================================================
/**
*/
class Project10PrereqAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    Project10PrereqAudioProcessor();
    ~Project10PrereqAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    juce::dsp::Oscillator<Data<float>> osc;
    juce::dsp::Gain<float> gain;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Project10PrereqAudioProcessor)
};
