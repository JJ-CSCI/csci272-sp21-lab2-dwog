//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here
class GPS {
private:
     double latitude, longitude;
     Compass latitudeDirection, longitudeDirection;
 
 public:
     double getLatitude() const;
     double getLongitude() const;
     Compass getLatitudeDirection() const;
     Compass getLongitudeDirection() const;
 
     GPS(
     double latitude, double longitude,
     Compass latitudeDirection = Compass::N,
     Compass longitudeDirection = Compass::W);

         GPS(
         double latitude, Compass latitudeDirection,
         double longitude = 0.0,
         Compass longitudeDirection = Compass::W);

              GPS()
     {
     this->latitude = 0.0;
     this->longitude = 0.0;
     this->latitudeDirection =  Compass::N;
     this->longitudeDirection = Compass::W;
     }

};


double GPS::getLatitude() const
{
return this->latitude;
}

double GPS::getLongitude() const
{
    return this->longitude;
    }

Compass GPS::getLatitudeDirection() const
{
    return this->latitudeDirection;
}

Compass GPS::getLongitudeDirection() const
{
    return this->longitudeDirection;
}

GPS::GPS(double latitude, double longitude, Compass latitudeDirection, Compass longitudeDirection)
{
     this->latitude = ((latitude < 0.0) || (latitude > 90.0)) ? 0.0 : latitude;
     this->longitude = ((longitude < 0.0) || (longitude > 180.0)) ? 0.0 : longitude;
     this->latitudeDirection = ((latitudeDirection == Compass::W) || (latitudeDirection == Compass::E)) ? Compass::N : latitudeDirection;
     this->longitudeDirection = ((longitudeDirection == Compass::N) || (longitudeDirection == Compass::S)) ? Compass::W : longitudeDirection;
 }

 GPS::GPS(double latitude, Compass latitudeDirection, double longitude, Compass longitudeDirection)
{
    this->latitude = ((latitude < 0.0) || (latitude > 90.0)) ? 0.0 : latitude;
    this->longitude = ((longitude < 0.0) || (longitude > 180.0)) ? 0.0 : longitude;
    this->latitudeDirection = ((latitudeDirection == Compass::W) || (latitudeDirection == Compass::E)) ? Compass::N : latitudeDirection;
    this->longitudeDirection = ((longitudeDirection == Compass::N) || (longitudeDirection == Compass::S)) ? Compass::W : longitudeDirection;
}





//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
