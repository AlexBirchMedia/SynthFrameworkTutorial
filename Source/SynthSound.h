/*
  ==============================================================================

    SynthSound.h
    Created: 13 Aug 2022 9:21:59pm
    Author:  alexb

  ==============================================================================
*/
#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:

    bool appliesToNote(int /*midiNoteNumber*/) override
    {
        return true;
    }

    bool appliesToChannel(int /* midiChannel */) override
    {
        return true;
    }

};
