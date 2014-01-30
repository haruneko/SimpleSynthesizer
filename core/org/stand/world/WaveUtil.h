#ifndef WAVEUTIL_H
#define WAVEUTIL_H

namespace org
{
namespace stand
{
namespace world
{

class Signal;

/**
 * @brief The WaveUtil class is a utility class for wave file.
 */
class WaveUtil
{
public:
    static Signal *read(const char *filepath);
    static void write(const char *filepath, const Signal *signal);
};

}
}
}

#endif // WAVEUTIL_H
