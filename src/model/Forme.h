#ifndef __FORME_H__
#define __FORME_H__

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class Forme {
public:
    Forme();
    Forme(const std::string& label); // Avec un label
    Forme(const std::string& label, const std::string& colorOutline, const std::string& colorFill); // Avec un label et des couleurs
    Forme(const Forme& forme); // Construction par recopie
    virtual ~Forme();

    // Operator d'affectation
    Forme& operator=(const Forme& forme);

    // Setter
    void setLabel(const std::string& str);
    void setcolorOutline(const std::string& str);
    void setcolorFill(const std::string& str);

    // Getter
    std::string getLabel() const;
    std::string getcolorOutline() const;
    std::string getcolorFill() const;

    virtual float surface() const { return 0.0f; }
    virtual float perimeter() const { return 0.0f; }

	// Fonctions utilitaires
    virtual void display() const = 0;
	virtual void move(int , int) = 0;
    virtual void draw(wxPaintDC& dc) = 0;
    virtual std::string toSVG() = 0;

/*
	virtual void zoom(int ) {};
	virtual void rotation(int ) {};
*/


protected: 
    std::string label;
    std::string colorOutline;
    std::string colorFill;


};

#endif // __FORME_H__
