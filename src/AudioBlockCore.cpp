//
// Created by romi on 3/30/24.
//
#include <iostream>
#include "./lib/AudioBlockCore.hpp"

//Class Functions
AudioBlockCore::AudioBlockCore(AudioBlockType type) {
    this->type = type;
}
AudioBlockCore::~AudioBlockCore() = default;

//Basic Functions
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

AudioBlockType AudioBlockCore::getType() {
//    return type;
//返回字符串
    switch (type) {
        case AudioBlockType_Midi:
            return "Midi";
        case AudioBlockType_Audio:
            return "Audio";
    }
}

//Type Functions
AudioBlockMidi::AudioBlockMidi(std::vector<std::string> midiData) : AudioBlockCore(AudioBlockType_Midi) {
    this->midiData = midiData;
}

AudioBlockAudio::AudioBlockAudio(std::vector<float> audioData) : AudioBlockCore(AudioBlockType_Audio) {
    this->audioData = audioData;
}
