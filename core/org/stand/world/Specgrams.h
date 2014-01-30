#ifndef SPECGRAMS_H
#define SPECGRAMS_H

namespace org
{
namespace stand
{
namespace world
{

/**
 * @brief The AnalysisResult class represents an analysis result of voice signal by WORLD.
 */
class Specgrams
{
public:
    virtual ~Specgrams();
    Specgrams(const Specgrams &other);

    double msFramePeriod;
    int frameLength;
    int fftSize;
    double *f0;
    double *timeAxis;
    double **specgram;
    double **residual;

    double msLength() const;

    static Specgrams *create(int frameLength, int fftSize, double msFramePeriod);
private:
    Specgrams(int frameLength, int fftSize, double msFramePeriod);
    void copy(double *dst, const double *src, int length);
    static double **allocMatrix(int frameLength, int fftSize);
};

}
}
}

#endif // SPECGRAMS_H
