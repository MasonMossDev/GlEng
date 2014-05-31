class ObjectMorpher
{
public:
	void SetValues( double xPos, double yPos, double zPos, double xScale, double yScale, double zScale, double rCol, double gCol, double bCol );

protected:
	double XPos, YPos, ZPos;
	double XScale, YScale, ZScale;
	double RCol, GCol, BCol;
};