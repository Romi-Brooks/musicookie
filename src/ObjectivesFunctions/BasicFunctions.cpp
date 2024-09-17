//
// Created by Romi on 24-7-13.
//

#include "../../lib/ObjectivesFunctions/BasicFunctions.hpp"

// forward function
void FindEntity_Block() {
    // What sh
}

bool CheckName(const std::string& User_Input_Name) {
    // 检查字符串是否超过128个字符
    if (User_Input_Name.length() > 128) {
        LogSystem(Log_ERROR) << Log_ERROR << "Name is too long.";
        return false;
    }

    // 正则表达式检查特殊字符
    std::regex specialChars("[^a-zA-Z0-9_]");
    if (std::regex_search(User_Input_Name, specialChars)) {
        LogSystem(Log_ERROR) << Log_ERROR << "Name contains special characters.";
        return false;
    }

    return true;
}

void GetMIDIBlockInfo() {
    std::cout <<" ";
}

void GetAudioBlockInfo() {
    std::cout <<" ";
}


void CreateAudioBlock() {
    while (true) {
        // Get Name of block
        std::string User_Type_Name;
        std::cout << "Enter the name of the Audio Block: ";
        std::cin >> User_Type_Name;
            // Check The block Name
            if (CheckName(User_Type_Name) == true) {
                // Creat an Audio Block
                EntityBlockCore block(EntityBlockType_Audio);
                block.SetName(User_Type_Name);
                break;
            } else {
                std::cout << "Invalid name. Please try again." << std::endl;
            }
    }
}
void CreateMIDIBlock() {
    while (true) {
        // Get Name of block
        std::string User_Type_Name;
        std::cout << "Enter the name of the MIDI Block: ";
        std::cin >> User_Type_Name;
            // Check The block Name
            if (CheckName(User_Type_Name) == true) {
                // Creat an MIDI Block
                EntityBlockCore block(EntityBlockType_Midi);
                block.SetName(User_Type_Name);
                break;
            } else {
                std::cout << "Invalid name. Please try again." << std::endl;
            }
    }
}


//
// EntityBlockCore* FindAudio_Entity(const std::vector<EntityBlockAudio>& User_Input_Entity,
//                                   const std::string& User_Input_Name)
// {
//     for (const auto& F_Entity : User_Input_Entity) {
//         if (F_Entity.GetName() == User_Input_Name) {
//             return const_cast<EntityBlockAudio*>(&F_Entity); // 返回匹配的实体对象指针
//         }
//     }
//     LogSystem(Log_ERROR) << "Entity with name " << User_Input_Name << " not found.";
//     return nullptr;
// }
