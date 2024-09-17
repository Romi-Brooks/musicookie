#include <iostream>
#include "../lib/ObjectivesFunctions/BasicFunctions.hpp"
#include "../lib/CoreObjectives/EntityBlockCore.hpp"
#include  "../lib/IOSystem/LogSystem.hpp"


int main() {
    LogSystem(Log_INFO) << Log_INFO << "Under Testing...";
    /* Creat the Audio block*/
    CreateAudioBlock();
    /* Creat the MIDI block*/
    CreateMIDIBlock();
    /* Get the Entity Block*/
    GetAudioBlockInfo();
    GetMIDIBlockInfo();
    return 0;
}

