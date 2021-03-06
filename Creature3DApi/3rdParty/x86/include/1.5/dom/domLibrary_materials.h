#ifndef __domLibrary_materials_h__
#define __domLibrary_materials_h__

#include <dae/daeDocument.h>
#include <dom/domTypes.h>
#include <dom/domElements.h>

#include <dom/domAsset.h>
#include <dom/domMaterial.h>
#include <dom/domExtra.h>
class DAE;

/**
 * The library_materials element declares a module of material elements.
 */
class domLibrary_materials : public daeElement
{
public:
	virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::LIBRARY_MATERIALS; }
	static daeInt ID() { return 121; }
	virtual daeInt typeID() const { return ID(); }
protected:  // Attributes
/**
 *  The id attribute is a text string containing the unique identifier of
 * this element.  This value must be unique within the instance document.
 * Optional attribute. 
 */
	xsID attrId;
/**
 *  The name attribute is the text string name of this element. Optional attribute.
 */
	xsToken attrName;

protected:  // Elements
/**
 * The library_materials element may contain an asset element. @see domAsset
 */
	domAssetRef elemAsset;
/**
 * There must be at least one material element. @see domMaterial
 */
	domMaterial_Array elemMaterial_array;
/**
 * The extra element may appear any number of times. @see domExtra
 */
	domExtra_Array elemExtra_array;

public:	//Accessors and Mutators
	/**
	 * Gets the id attribute.
	 * @return Returns a xsID of the id attribute.
	 */
	xsID getId() const { return attrId; }
	/**
	 * Sets the id attribute.
	 * @param atId The new value for the id attribute.
	 */
	void setId( xsID atId ) { *(daeStringRef*)&attrId = atId;
		if( _document != NULL ) _document->changeElementID( this, attrId );
	}

	/**
	 * Gets the name attribute.
	 * @return Returns a xsToken of the name attribute.
	 */
	xsToken getName() const { return attrName; }
	/**
	 * Sets the name attribute.
	 * @param atName The new value for the name attribute.
	 */
	void setName( xsToken atName ) { *(daeStringRef*)&attrName = atName;}

	/**
	 * Gets the asset element.
	 * @return a daeSmartRef to the asset element.
	 */
	const domAssetRef getAsset() const { return elemAsset; }
	/**
	 * Gets the material element array.
	 * @return Returns a reference to the array of material elements.
	 */
	domMaterial_Array &getMaterial_array() { return elemMaterial_array; }
	/**
	 * Gets the material element array.
	 * @return Returns a constant reference to the array of material elements.
	 */
	const domMaterial_Array &getMaterial_array() const { return elemMaterial_array; }
	/**
	 * Gets the extra element array.
	 * @return Returns a reference to the array of extra elements.
	 */
	domExtra_Array &getExtra_array() { return elemExtra_array; }
	/**
	 * Gets the extra element array.
	 * @return Returns a constant reference to the array of extra elements.
	 */
	const domExtra_Array &getExtra_array() const { return elemExtra_array; }
protected:
	/**
	 * Constructor
	 */
	domLibrary_materials(DAE& dae) : daeElement(dae), attrId(), attrName(), elemAsset(), elemMaterial_array(), elemExtra_array() {}
	/**
	 * Destructor
	 */
	virtual ~domLibrary_materials() {}
	/**
	 * Overloaded assignment operator
	 */
	virtual domLibrary_materials &operator=( const domLibrary_materials &cpy ) { (void)cpy; return *this; }

public: // STATIC METHODS
	/**
	 * Creates an instance of this class and returns a daeElementRef referencing it.
	 * @return a daeElementRef referencing an instance of this object.
	 */
	static DLLSPEC daeElementRef create(DAE& dae);
	/**
	 * Creates a daeMetaElement object that describes this element in the meta object reflection framework.
	 * If a daeMetaElement already exists it will return that instead of creating a new one. 
	 * @return A daeMetaElement describing this COLLADA element.
	 */
	static DLLSPEC daeMetaElement* registerElement(DAE& dae);
};


#endif
