/******************************************************************************
 * Filename:        eSRIM_classes.h
 * Project:         eSRIM
 * Author:          Nathaniel Thomas
 * Date Created:    March 8, 2024
 * Date Modified:   March 8, 2024
 * File Version:    1.0
 * Group:           Dr. Shao's RMSLCF Group
 *
 * Description:
 * This file contains the class declarations for the eSRIM program. 
 * implementations are in eSRIM_classes.cpp
 * 
 *
 * Revision History
 * 1.0:
 * - File created and class declarations added
 *
 *****************************************************************************/
#ifndef ESRIM_CLASSES_H
#define ESRIM_CLASSES_H

// Includes
#include <array>
#include <filesystem>
#include <iostream> 
#include <memory>
#include <mutex>
#include <random>
#include <thread>
#include <tuple>
#include <vector>

// Local header files
#include "constants.h"


// Debug compiler directives 
#ifdef DEBUG_MODE
#define DEBUG_PRINT(x) std::cout << x << std::endl;
#else
#define DEBUG_PRINT(x)
#endif

// Namespaces
namespace fs = std::filesystem;

// Class and function declarations (to be moved to a header file in a later 
// version)
struct Coordinate {
    double x;
    double y;
    double z;
    size_t depth;
};

struct Velocity{
    double zAngle;
    double xAngle;
    double energy;
};


class InputFields {
private:
    // Private constructors to prevent external instantiation 
    InputFields();
    InputFields(
        double charge,
        double electronStoppingEnergy,
        double energy,
        bool enableDamageCascade,
        const std::string& electronScreeningParametersFilename,
        const std::string& inputDirectoryName,
        double ionDisplacementEnergy,
        double ionStoppingEnergy,
        bool logSingleDisplacement,
        double mass,
        const std::string& mottScatteringParametersFilename,
        size_t numAngleDivisors,
        size_t numElecScreeningPotentialElements,
        size_t numFlyingDistances,
        size_t numMottScatteringPotentialElements,
        const std::string& outputFileEndMarker,
        const std::string& outputFileExtension,
        const std::string& outputCoordinateFilename,
        const std::string& outputDirectory,
        double range,
        size_t simulationCount,
        double substrateCharge,
        double substrateDensity,
        double substrateMass,
        const std::string& settingsFilename,
        ParticleType type,
        bool logEndOfFlyingDistanceOnly,
        bool logStoppingPointOnly,
        bool progressChecking,
        size_t numThreads);

    InputFields(const std::string& settingsFilename);

    // Static instance of the class
    static std::shared_ptr<InputFields> instance;

    // Member variables
    double charge;
    double electronStoppingEnergy;
    double energy;
    bool enableDamageCascade;
    std::string electronScreeningParametersFilename;
    std::string inputDirectoryName;
    double ionDisplacementEnergy;
    double ionStoppingEnergy;
    bool logSingleDisplacement;
    double mass;
    std::string mottScatteringParametersFilename;
    size_t numAngleDivisors;
    size_t numElecScreeningPotentialElements;
    size_t numFlyingDistances;
    size_t numMottScatteringPotentialElements;
    std::string outputFileEndMarker;
    std::string outputFileExtension;
    std::string outputCoordinateFilename;
    std::string outputDirectory;
    double range;
    size_t simulationCount;
    double substrateCharge;
    double substrateDensity;
    double substrateMass;
    std::string settingsFilename;
    ParticleType type;
    bool logEndOfFlyingDistanceOnly;
    bool logStoppingPointOnly;
    bool progressChecking;
    size_t numThreads;

    // Functions
    bool parseSetting(
        const std::string& line,    
        std::string& name,
        std::string& value);
    bool stringToBool(const std::string& str);

public:
    // Static methods to get the instance of the class
    static std::shared_ptr<InputFields> getInstance();
    static std::shared_ptr<InputFields> getInstance(
    const std::string& settingsFilename);

    // Getters
    bool getEnableDamageCascade() const;
    double getElectronStoppingEnergy() const;
    bool getLogSingleDisplacement() const;
    double getCharge() const;
    double getEnergy() const;
    double getIonDisplacementEnergy() const;
    double getIonStoppingEnergy() const;
    double getMass() const;
    double getRange() const;
    double getSubstrateCharge() const;
    double getSubstrateDensity() const;
    double getSubstrateMass() const;
    ParticleType getType() const;
    size_t getSimulationCount() const;
    size_t getNumAngleDivisors() const;
    size_t getNumElecScreeningPotentialElements() const;
    size_t getNumFlyingDistances() const;
    size_t getNumMottScatteringPotentialElements() const;
    const std::string& getElectronScreeningParametersFilename() const;
    const std::string& getInputDirectoryName() const;
    const std::string& getMottScatteringParametersFilename() const;
    const std::string& getOutputCoordinateFilename() const;
    const std::string& getOutputDirectory() const;
    const std::string& getOutputFileEndMarker() const;
    const std::string& getOutputFileExtension() const;
    const std::string& getSettingsFilename() const;
    bool getLogEndOfFlyingDistanceOnly() const;
    bool getLogStoppingPointOnly() const;
    bool getProgressChecking() const;
    size_t getNumThreads() const;

    // Setters
    void setCharge(double charge);
    void setElectronScreeningParametersFilename(const std::string& filename);
    void setElectronStoppingEnergy(double energy);
    void setEnableDamageCascade(bool enable);
    void setEnergy(double energy);
    void setInputDirectoryName(const std::string& name);
    void setIonDisplacementEnergy(double energy);
    void setIonStoppingEnergy(double energy);
    void setLogSingleDisplacement(bool log);
    void setMass(double mass);
    void setMottScatteringParametersFilename(const std::string& filename);
    void setNumAngleDivisors(size_t divisors);
    void setNumElecScreeningPotentialElements(size_t elements);
    void setNumFlyingDistances(size_t distances);
    void setNumMottScatteringPotentialElements(size_t elements);
    void setOutputCoordinateFilename(const std::string& filename);
    void setOutputDirectory(const std::string& directory);
    void setOutputFileEndMarker(const std::string& marker);
    void setOutputFileExtension(const std::string& extension);
    void setRange(size_t range);
    void setSettingsFilename(const std::string& filename);
    void setSimulationCount(size_t count);
    void setSubstrateCharge(double substrateCharge);
    void setSubstrateDensity(double substrateDensity);
    void setSubstrateMass(double substrateMass);
    void setType(ParticleType type);
    void setLogEndOfFlyingDistanceOnly(bool logEndOfFlyingDistanceOnly);
    void setLogStoppingPointOnly(bool logStoppingPointOnly);
    void setProgressChecking(bool progressChecking);
    void setNumThreads(size_t numThreads);

    // Functions
    void readSettingsFromFile();
    std::string printInputFields() const;
};


class Bombardment;

class Particle {
    protected:
        // Static member variables
        static std::mt19937 randomGenerator;
        static std::uniform_real_distribution<double> randomDistribution;
        static std::mutex randomGeneratorLock;

        // Member variables
        std::vector<Coordinate> coordinate_vector;
        Coordinate coordinate;
        Velocity velocity;
        bool enableDamageCascade;
        double &energy = velocity.energy;
        const double charge;
        const double mass;
        const double substrateCharge;
        const double substrateDensity;
        const double substrateMass;
        const ParticleType type;
        const double range;
        double ionDisplacementEnergy;
        double ionStoppingEnergy;
        std::shared_ptr<InputFields> input;
        std::weak_ptr<Bombardment> bombardment;

        // Static functions
        static double random();

    public:
        // Constructors
        Particle(
            const Coordinate& coordinate,
            const Velocity& velocity,
            std::shared_ptr<InputFields> input,
            std::weak_ptr<Bombardment> bombardment);

        Particle(
            const Coordinate& coordinate,
            const Velocity& velocity,
            bool enableDamageCascade,
            double charge,
            double mass,
            double substrateCharge,
            double substrateDensity,
            double substrateMass,
            ParticleType type,
            double range,
            double ionDisplacementEnergy,
            double ionStoppingEnergy,   
            std::shared_ptr<InputFields> input,
            std::weak_ptr<Bombardment> bombardment); 

        // Destructor
        virtual ~Particle();

        // Modifiers
        virtual void addCoordinate(const Coordinate& coordinate);

        // Accessors
        virtual const Coordinate& getCoordinate() const;
        virtual const std::vector<Coordinate>& getCoordinates() const;
        virtual size_t getNumParticles() const;

        // Member functions
        virtual void fire();
        inline virtual double atomicSpacing() const;
        void relativeToAbsoluteVelocity(
            Velocity& newVelocity,
            Velocity& targetVelocity
            ) const noexcept;
        virtual double sign(const double x) const noexcept;
        virtual inline Coordinate calculateNewCoordinate();
        void createSubstrateKnockon(const Coordinate& newCoordinate,
            const Velocity&
            targetVelocity);

        // Public static functions
        static void seedRandomGenerator();
};  


class Ion : public Particle {
    public:
        // Constructor
        Ion(const Coordinate& coordinate,
            const Velocity& velocity,
            std::shared_ptr<InputFields> input,
            std::weak_ptr<Bombardment> bombardment);

        Ion(const Coordinate& coordinate,
            const Velocity& velocity,
            bool enableDamageCascade,
            double charge,
            double mass,
            double substrateCharge,
            double substrateDensity,
            double substrateMass,   
            ParticleType type,
            double range,
            double ionDisplacementEnergy,
            double ionStoppingEnergy,
            std::shared_ptr<InputFields> input,
            std::weak_ptr<Bombardment> bombardment); 

        // Actions
        void fire() override;
        double F(double X, double COLUMBIAVK, double AU);
        double DF(double X, double COLUMBIAVK, double AU);
        void recoilEnergyAndVelocity(
            Velocity& newVelocity,
            Velocity& targetVelocity);
        double electronicStoppingEnergy();
        virtual const size_t& getDepth() const;
        inline Coordinate calculateNewCoordinate() override;
};


class Substrate : public Ion {
    private:
        size_t &depth = coordinate.depth;

    public:
        // Constructors
        Substrate(
            const Coordinate& coordinate,
            const Velocity& velocity,   
            std::shared_ptr<InputFields> input,
            std::weak_ptr<Bombardment> bombardment);
        // Functions
        virtual const size_t& getDepth() const override;
};


class Electron : public Particle {
    private:
        static std::vector<
            std::array<std::array<
            double,
            Constants::numMottkParam>,
            Constants::numMottjParam>>
            mottScatteringParams;
        
        static std::vector<
            std::array<
            double,
            Constants::numElecScreeningPotentialParams>> 
            elecScreeningParams;

        static std::vector<double> divisionAngles;

        std::vector<double> randomCrossSections;
        std::vector<double> flyingDistances;
        std::vector<double> scatteringAngles;
        std::vector<double> partialCrossSections;
        std::vector<double> elasticEnergyLoss;

        double correctionFactor;
        double electronStoppingEnergy;
        
    public:
        // Constructor
        Electron(
            const Coordinate& initialCoordinate,
            const Velocity& initialVelocity,
            std::shared_ptr<InputFields> input,
            std::weak_ptr<Bombardment> bombardment);
        
        // Initializer
        static inline double findAngle(
            size_t i,
            std::shared_ptr<InputFields> input);
        static void readParametersAndInitialize(
            std::shared_ptr<InputFields> input);

        // Functions
        void fire();
        double getMottDifferentialCrossSection(double Theta);
        void generateRandomCrossSections();
        double generateFlyingDistances(double totalMottCrossSection);
        double getMottTotalCrossSection();
        void generateIntegratedCrossSections(double totalMottCrossSection);
        double getElasticEnergyLoss();
        double getIonizationEnergyLoss();
        inline double getBremsstrahlung();
        inline Coordinate calculateNewElectronCoordinate(size_t i);
};

class Simulation;

class Bombardment : public std::enable_shared_from_this<Bombardment> {
    private:
        std::vector<std::unique_ptr<Particle>> particles;
        std::weak_ptr<Simulation> simulation;
        size_t id;
    
    public:
        // Constructors
        Bombardment(std::weak_ptr<Simulation> simulation, size_t id);

        // Destructor
        ~Bombardment();

        // Accessor
        const std::vector<std::unique_ptr<Particle>>& getParticles() const;

        void initiate(std::shared_ptr<InputFields> inputFields);
        void addParticle(std::unique_ptr<Particle> particle);
        void popParticle();
};

class Simulation : public std::enable_shared_from_this<Simulation> {
    private:
        size_t bombardmentCount;
        std::shared_ptr<InputFields> input;
        std::vector<std::shared_ptr<Bombardment>> bombardments;
        fs::path outputPath;
        std::mutex fileLock;
        std::mutex counterLock;
        std::vector<std::thread> threads;
        u_int64_t progressCounter;

    public:
        // Constructors
        Simulation();
        Simulation(std::shared_ptr<InputFields> input);

        // Destructors
        ~Simulation();

        // Accessors
        std::shared_ptr<InputFields> getInput();
        size_t getBombardmentSize();
        size_t getBombardmentCapacity();

        // Modifiers
        void addParticle();

        // Functions
        void initiate();

        void writeData(
            OutputType outputType,
            const std::vector<std::unique_ptr<Particle>>& particles,
            size_t simulationID);
        bool fileIsWritten(const fs::path filename);
        void renameFileWithTimestamp(const std::string& filename);
        std::string getCurrentDateTime();
        void checkOutputFiles();
        void updateProgressCounter();
};

#endif