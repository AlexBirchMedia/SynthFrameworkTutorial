/*
  ==============================================================================

    SynthVoice.h
    Created: 13 Aug 2022 9:22:32pm
    Author:  alexb

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "../Maximillian/src/maximilian.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }

    //=====================================================================

    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override
    {
        frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        std::cout << midiNoteNumber << std::endl;
    }

    //=====================================================================

    void stopNote(float velocity, bool allowTailOff) override
    {
        clearCurrentNote();
    }

    //=====================================================================

    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override
    {
        for (int sample = 0; sample < numSamples; ++sample)
        {

            double theWave = osc1.sinewave(440);

            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
            {
                outputBuffer.addSample(channel, startSample, theWave);
            }

            ++startSample;
        }



    }

    //=====================================================================

    void pitchWheelMoved(int newPitchWheelValue) override
    {

    }

    //=====================================================================

    void controllerMoved(int controllerNumber, int newControllerValue) override
    {

    }

    

private:
    double level;
    double frequency;

    maxiOsc osc1;
};