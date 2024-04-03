//
// Created by romi on 3/30/24.
//
#include <iostream>
#include <utility>
#include "../lib/CoreObjective/AudioBlockCore.hpp"

//Class Functions
AudioBlockCore::AudioBlockCore(AudioBlockType type) {
    this->BlockType = std::to_string(type);
}

AudioBlockCore::~AudioBlockCore() = default;

//Basic Functions
//Construction
void AudioBlockCore::SetName(std::string UserBlockName) {
    AudioBlockName = std::move(UserBlockName);
}

//Get Name
std::string AudioBlockCore::GetName() {
    return AudioBlockName;
}

//Get, and set Pan
int AudioBlockCore::GetPan() {
    return AudioBlockPan;
}
void AudioBlockCore::SetPan(int UserPan) {
    AudioBlockPan = UserPan;
}

//Get, and set Vol
int AudioBlockCore::GetVol() {
    return AudioBlockVol;
}
void AudioBlockCore::SetVol(int UserVol) {
    AudioBlockVol = UserVol;
}

//Get Type
AudioBlockType AudioBlockCore::GetType() {
    return static_cast<AudioBlockType>(std::stoi(BlockType));
}
std::string AudioBlockCore::GetTypeName(){
        int TypeCode = this->GetType(); // use this-> to call the function in the same class
        switch (TypeCode) {
            case AudioBlockType_Midi:
                return "Midi";
            case AudioBlockType_Audio:
                return "Audio";
            default:
                return "Unknown";
        }
    }

//Type Functions
AudioBlockMidi::AudioBlockMidi(std::vector<std::string> midiData) : AudioBlockCore(AudioBlockType_Midi) {
    this->midiData = midiData;
}

AudioBlockAudio::AudioBlockAudio(std::vector<float> audioData) : AudioBlockCore(AudioBlockType_Audio) {
    this->audioData = audioData;
}
