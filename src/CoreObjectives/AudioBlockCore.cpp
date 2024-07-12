//
// Created by romi on 3/30/24.
//

#include <utility>

#include "../../lib/CoreObjectives/AudioBlockCore.hpp"

//Class Functions
EntityBlockCore::EntityBlockCore(EntityBlockType type) {
    this->BlockType = std::to_string(type);
}

EntityBlockCore::~EntityBlockCore() = default;

//Basic Functions
//Construction
void EntityBlockCore::SetName(std::string UserBlockName) {
    EntityBlockName = std::move(UserBlockName);
}

//Get Name
std::string EntityBlockCore::GetName() {
    return EntityBlockName;
}

//Get, and set Pan
int EntityBlockCore::GetPan() const {
    return EntityBlockPan;
}
void EntityBlockCore::SetPan(int UserPan) {
    EntityBlockPan = UserPan;
}

//Get, and set Vol
int EntityBlockCore::GetVol() const {
    return EntityBlockVol;
}
void EntityBlockCore::SetVol(int UserVol) {
    EntityBlockVol = UserVol;
}

//Get Type
EntityBlockType EntityBlockCore::GetType() const {
    return static_cast<EntityBlockType>(std::stoi(BlockType));
}
std::string EntityBlockCore::GetTypeName() const{
    /*Need to switch-statement rewrite*/

        int TypeCode = this->GetType(); // use this-> to call the function in the same class
        switch (TypeCode) {
            case EntityBlockType_Midi:
                return "Midi";
            case EntityBlockType_Audio:
                return "Audio";
            default:
                return "Unknown";
        }
    }

//Type Functions
EntityBlockMidi::EntityBlockMidi(std::vector<std::string> midiData) : EntityBlockCore(EntityBlockType_Midi) {
    this->midiData = std::move(midiData);
}

EntityBlockAudio::EntityBlockAudio(std::vector<float> audioData) : EntityBlockCore(EntityBlockType_Audio) {
    this->audioData = std::move(audioData);
}
