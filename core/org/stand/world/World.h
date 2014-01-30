#ifndef WORLD_H
#define WORLD_H

namespace org
{
namespace stand
{
namespace world
{

class Specgrams;
class Signal;

class AnalysisAndSynthesis
{
public:
    virtual ~AnalysisAndSynthesis(){ }
    virtual Specgrams *analyze(Signal *wave, double msFramePeriod) = 0;
    virtual Signal *synthesize(Specgrams *spectrograms, int samplingFrequency) = 0;
};

/**
 * @brief The World class implements AnalysisAndSynthesis.
 *        This class represents WORLD.
 */
class World : public AnalysisAndSynthesis
{
public:
    Specgrams *analyze(Signal *wave, double msFramePeriod);
    Signal *synthesize(Specgrams *spectrograms, int samplingFrequency);
};

}
}
}

#endif // WORLD_H
