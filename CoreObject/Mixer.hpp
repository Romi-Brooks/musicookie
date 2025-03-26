#ifndef MIXER_HPP
#define MIXER_HPP
#include <vector>

class Channel {
private:
    std::string ChannelName;
    unsigned int ChannelID;
    float ChanneVolume;
    int ChannePan;
    bool Mute;
    bool Solo;
    double* Audio_IN;
    double* Audio_Out;

    public:
        // Defualt Constructor
        Channel(std::string  I_ChannelName, unsigned int I_ChannelID);

        // Info Get Interface
        auto GetChannelName() const {return ChannelName;}
        auto GetChannelVolume() const {return ChanneVolume;}
        auto GetChannelPan() const {return ChannePan;}
        auto GetChannelID() const {return ChannelID;}
        auto IsSolo() const {return Solo;}
        auto IsMute() const {return Mute;}

        // Info Set Interface
        void SetChannelVolume(float I_ChannelVolume);
        void SetChannelPan(int I_ChannelPan);
        void MuteAction();
        void SoloAction();

};

class Mixer {
    private:
        // Channel Vector
        std::vector<Channel> MixerChannels;
        unsigned int NextFreeID;

    public:
        Mixer() : NextFreeID(1) {};

        // User Action Interface
        void AddMixerChannel(const std::string& I_ChannelName);
        void Mixer_SetChannelVolume(float I_ChannelVolume, unsigned int I_ChannelID);
        void Mixer_SetChannelPan(int I_ChannelPan, unsigned int I_ChannelID);
        void Mixer_MuteAction(unsigned int I_ChannelID);
        void Mixer_SoloAction(unsigned int I_ChannelID);
        void Mixer_Printer();
};



#endif //MIXER_HPP
