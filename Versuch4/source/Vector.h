//
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vector.h
// Inhalt: Headerdatei der Klasse Vector
//

#ifndef Vector_H
#define Vector_H

class Vector
{
   public:
    Vector(double x, double y, double z);
    ~Vector();

    double getX() const;
    double getY() const;
    double getZ() const;
      
    Vector sub(const Vector& input) const;
    Vector add(const Vector& input) const;
    
    double length() const;
    bool ortho(const Vector& input) const;
    double scalarProd(const Vector& input) const;

    double angle(const Vector& input) const;
    double angleInDegree(const Vector& input) const;
    
    void rotateAroundZ(const double rad);
    
    void ausgabe() const;
    bool hasValues(int x, int y, int z) const;

    Vector rotZ(double angle) const;
    Vector rotZInDegree(double angle) const;

   private:
    double x;
    double y;
    double z;

};

#endif
