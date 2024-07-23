//
// Created by Romi on 24-7-13.
//

#ifndef BASICFUNCTIONS_HPP
#define BASICFUNCTIONS_HPP

#include <iostream>
#include <regex>

#include "../../lib/IOSystem/LogSystem.hpp"
#include "../../lib/CoreObjectives/EntityBlockCore.hpp"

bool CheckName_Blocks(const std::string& User_Input_Name);
void CheckNum_Pan();
void CheckNum_Vol();
void FindEntity_Block();

// EntityBlockCore* FindAudio_Entity(const std::vector<EntityBlockAudio>& User_Input_Entity,
                                  // const std::string& User_Input_Name);

void CreateAudioBlock();
void CreateMIDIBlock();

void GetBlockInfo();
#endif //BASICFUNCTIONS_HPP
