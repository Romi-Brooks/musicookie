//
// Created by romi on 3/30/24.
//

#ifndef MUSICOOKIE_AUDIOBLOCKCORE_HPP
#define MUSICOOKIE_AUDIOBLOCKCORE_HPP
#include <iostream>
#include <utility>
#include <vector>
#include <string>

enum EntityBlockType {
    EntityBlockType_Midi,
    EntityBlockType_Audio,
};

class EntityBlockCore {
    public:
        //Audio Block Basic Functions
        //Constructor
        explicit EntityBlockCore(EntityBlockType type);
        //Destructor:
        virtual ~EntityBlockCore();

        //Get Name
        std::string GetName();
        //Give Name
        void SetName(std::string UserBlockName);
        //Get Vol
        [[nodiscard]] int GetVol() const;
        //Set Vol
        void SetVol(int UserVol);
        //Get Pan
        [[nodiscard]] int GetPan() const;
        //Set Pan
        void SetPan(int UserPan);
        //Get Type
        [[nodiscard]] EntityBlockType GetType() const;
        [[nodiscard]] std::string GetTypeName() const; // Trans the Type enum index num to string, what a fucking tip.

    private:
        //Audio Block Basic Settings
        //Name
        std::string EntityBlockName;
        //Vol
        int EntityBlockVol = 80;
        //Pan
        int EntityBlockPan = 0;
        //Type
        std::basic_string<char> BlockType;
};














//This class is a subclass of AudioBlockCore, and is used to store MIDI data for synthesis
class EntityBlockMidi : public EntityBlockCore {
    public:
        explicit EntityBlockMidi(std::vector<std::string> midiData);
        std::vector<std::string> midiData;

    private:
        std::vector<std::string> _midiData;
        //Collector
        std::vector<EntityBlockMidi> Vector_of_MIDI_Blocks;

};




//This class is a subclass of AudioBlockCore, and is used to store audio data for sample playback
class EntityBlockAudio : public EntityBlockCore {
    public:
        explicit EntityBlockAudio(std::vector<float> audioData);
        std::vector<float> audioData;
    private:
        std::vector<float> _audioData;
        //Collector
        std::vector<EntityBlockAudio> Vector_of_Audio_Blocks;
};

#endif //MUSICOOKIE_AUDIOBLOCKCORE_HPP
