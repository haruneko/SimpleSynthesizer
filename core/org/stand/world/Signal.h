#ifndef SIGNAL_H
#define SIGNAL_H

namespace org
{
namespace stand
{
namespace world
{

/**
 * @brief The Signal class represents a vocal signal synthesized by WORLD.
 */
class Signal
{
public:
    Signal(int length, int samplingFrequency);
    virtual ~Signal();

    void clear();

    double *wave;
    int length;
    int samplingFrequency;

private:
};

}
}
}

#endif // SIGNAL_H
