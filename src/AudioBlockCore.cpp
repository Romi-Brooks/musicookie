//
// Created by romi on 3/30/24.
//
#include "./lib/AudioBlockCore.hpp"

void AudioBlockCore::SetName(std::string UserBlockName) {
    AudioBlockName = UserBlockName;
}
std::string AudioBlockCore::GetName() {
    return AudioBlockName;
}

int AudioBlockCore::GetPan() {
    return AudioBlockPan;
}
void AudioBlockCore::SetPan(int UserPan) {
    AudioBlockPan = UserPan;
}

int AudioBlockCore::GetVol() {
    return AudioBlockVol;
}
void AudioBlockCore::SetVol(int UserVol) {
    AudioBlockVol = UserVol;
}

AudioBlockMidi::AudioBlockMidi(std::vector<std::string> midiData) : AudioBlockCore(AudioBlockType_Midi) {
    this->midiData = midiData;
}

AudioBlockAudio::AudioBlockAudio(std::vector<float> audioData) : AudioBlockCore(AudioBlockType_Audio) {
    this->audioData = audioData;
}
