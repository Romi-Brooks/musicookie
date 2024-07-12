//
// Created by Romi on 24-7-13.
//

#ifndef BASICFUNCTIONS_HPP
#define BASICFUNCTIONS_HPP
void CreateAudioBlock() {
    //    get user input name
    std::string name;
    std::cout << "Enter the name of the audio block: ";
    std::cin >> name;

    EntityBlockCore block(EntityBlockType_Audio);
    block.SetName(name);
    std::cout << "Block Name: " << block.GetName() << std::endl;
    std::cout << "Block Pan: " << block.GetPan() << std::endl;
    std::cout << "Block Vol: " << block.GetVol() << std::endl;
    std::cout << "Block Type: " << block.GetTypeName() << std::endl;
}
void CreateMIDIBlock() {
    //    get user input name
    std::string name;
    std::cout << "Enter the name of the midi block: ";
    std::cin >> name;

    EntityBlockCore block(EntityBlockType_Midi);
    block.SetName(name);
    std::cout << "Block Name: " << block.GetName() << std::endl;
    std::cout << "Block Pan: " << block.GetPan() << std::endl;
    std::cout << "Block Vol: " << block.GetVol() << std::endl;
    std::cout << "Block Type: " << block.GetTypeName() << std::endl;
}
#endif //BASICFUNCTIONS_HPP
