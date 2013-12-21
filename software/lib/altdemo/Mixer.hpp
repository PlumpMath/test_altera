#ifndef MIXER_HPP_
#define MIXER_HPP_

#include "Vipcore.hpp"

class Mixer : public Vipcore{
  public:

    static int get_layer_x_offset_offset(int layer)
    {
        return 2 + ((layer-1) * 3);
    }

    static int get_layer_y_offset_offset(int layer)
    {
       return get_layer_x_offset_offset(layer) + 1;
    }

    static int get_layer_enabled_offset(int layer)
    {
        return get_layer_x_offset_offset(layer) + 2;
    }


    Mixer(long base_address) : Vipcore(base_address)
    {}

    void set_layer_enabled(int layer, bool enabled)
    {
        do_write(get_layer_enabled_offset(layer),(int)enabled);
    }

    void set_layer_enabled(int layer, int enabled)
    {
        do_write(get_layer_enabled_offset(layer),(int)enabled);
    }

    void set_layer_position(int layer, int x, int y)
    {
        do_write(get_layer_x_offset_offset(layer),x);
        do_write(get_layer_y_offset_offset(layer),y);
    }
};

#endif /*MIXER_HPP_*/

