#include <utility>
#include <vector>
#include <string>
#include "Block.hpp"

AudioBlock::AudioBlock(std::string I_AudioBlockName, double I_SampleRate) : AudioSampleRate(I_SampleRate), AudioBlockLength(0.0), AudioBlockName(std::move(I_AudioBlockName)) {}

void MidiBlock::AddMidiEvent(double I_MidiTime, int I_MidiNote, int I_MidiVelocity, const std::string &I_MidiType) {
    MidiEvent NewEvent = {I_MidiTime, I_MidiNote, I_MidiVelocity, I_MidiType};
    MIDIEvent.push_back(NewEvent);

    // 更新总长度
    if (I_MidiTime > MidiBlockLength) {
        MidiBlockLength = I_MidiTime;
    }
};
