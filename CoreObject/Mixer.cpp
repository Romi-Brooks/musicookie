#include <string>
#include <utility>
#include <iostream>
#include "Mixer.hpp"

// Forward Function
std::string MuteStatus(Channel& ChannelEntity) {
    if(ChannelEntity.IsMute() == true) {
        return "Muted";
    }else {
        return "Unmuted";
    }
}

std::string SoloStatus(Channel& ChannelEntity) {
    if(ChannelEntity.IsSolo() == true) {
        return "Soloed";
    }else {
        return "Unsoloed";
    }
}

Channel* GetSelectedChannel(std::vector<Channel>& ChannelVector, unsigned int I_ChannelID) {
    for(auto& Selected : ChannelVector) {
        if (Selected.GetChannelID() == I_ChannelID) {
            return &Selected;
        }
    }
    return nullptr; // Cannot Find Channel
}


Channel::Channel(std::string I_ChannelName, unsigned int I_ChannelID) : ChannelName(std::move(I_ChannelName)), ChannelID(I_ChannelID){
        ChanneVolume = 0.6;
        ChannePan = 0;
        Mute = false;
        Solo = false;
    }

void Channel::SetChannelVolume(float I_ChannelVolume) {
    this->ChanneVolume = I_ChannelVolume;
}

void Channel::SetChannelPan(int I_ChannelPan) {
    this->ChannePan = I_ChannelPan;
}

void Channel::MuteAction() {
    if(this->IsMute() == false) {
        this->Mute = true;
    }else {
        this->Mute = false;
    }
}

void Channel::SoloAction() {
    if(this->IsSolo() == false) {
        this->Solo = true;
    }else {
        this->Solo = false;
    }
}

void Mixer::AddMixerChannel(const std::string& I_ChannelName) {
    MixerChannels.emplace_back(I_ChannelName, NextFreeID);
    std::cout << I_ChannelName << " Channel Successfully Created in Mixer, Channel ID:" << NextFreeID << std::endl;
    NextFreeID++;
}

void Mixer::Mixer_SetChannelVolume(float I_ChannelVolume, unsigned int I_ChannelID) {
    auto* Selected = GetSelectedChannel(MixerChannels,I_ChannelID);
    if(Selected != nullptr) {
        Selected->SetChannelVolume(I_ChannelVolume);
        std::cout << "Changed " << Selected->GetChannelName() << " Channel (ID:" << Selected->GetChannelID() <<")'s Volume to:" << I_ChannelVolume << std::endl;
    }else {
        std::cout << "Channel with ID " << I_ChannelID << " not found." << std::endl;
        return;
    }
}

void Mixer::Mixer_SetChannelPan(int I_ChannelPan, unsigned int I_ChannelID) {
    auto* Selected = GetSelectedChannel(MixerChannels,I_ChannelID);
    if(Selected != nullptr) {
        Selected->SetChannelPan(I_ChannelPan);
        std::cout << "Changed " << Selected->GetChannelName() << " Channel (ID:" << Selected->GetChannelID() <<")'s Pan to:" << I_ChannelPan << std::endl;
    }else {
        std::cout << "Channel with ID " << I_ChannelID << " not found." << std::endl;
        return;
    }
}

void Mixer::Mixer_MuteAction(unsigned int I_ChannelID) {
    auto* Selected = GetSelectedChannel(MixerChannels,I_ChannelID);
    if(Selected != nullptr) {
        Selected->MuteAction();
        std::cout << "Now " << Selected->GetChannelName() << "Channel (ID:" << Selected->GetChannelID() <<") is " << MuteStatus(*Selected) << "." << std::endl;
    }else {
        std::cout << "Channel with ID " << I_ChannelID << " not found." << std::endl;
        return;
    }
}

void Mixer::Mixer_SoloAction(unsigned int I_ChannelID) {
    auto* Selected = GetSelectedChannel(MixerChannels,I_ChannelID);
    if(Selected != nullptr) {
        Selected->SoloAction();
        std::cout << "Now " << Selected->GetChannelName() << "Channel (ID:" << Selected->GetChannelID() <<") is " << SoloStatus(*Selected) << "." << std::endl;
    }else {
        std::cout << "Channel with ID " << I_ChannelID << " not found." << std::endl;
        return;
    }
}

void Mixer::Mixer_Printer() {
    for(auto& Selected : MixerChannels) {
        std::cout << "ID:" << Selected.GetChannelID() << " - Channel: " << Selected.GetChannelName() << " - Volume: " << Selected.GetChannelVolume() << " - Pan: " << Selected.GetChannelPan() << std::endl;
    }
}
