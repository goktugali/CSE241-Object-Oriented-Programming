/**
* <h1> Abstract Shape Class </h1>
* This class is written for Abstraction and gathering the compareTo interface implementation in "one" class. 
* Otherwise, (If this class is not written) all Shapes subclasses should implement compareTop interface.
* compareTo interface implemented and collected in one Abstract Class.
* @author Goktug Akin
* @since 2019
* @version HW7
*/

/*
 * CompareTo interface implemenastoynunu tek bir Abstract classda toplamak icin bu class yazildi.
 * Yazilmasaydi, her class (Rectangle,Triangle...) compareTo yu ayrı ayrı implement etmesi gerecekti
 * ama boyle bir durum gereksiz, hepsi icin ayni kod yazilacakti, o yüzden bu abstract classda topladım.
*/
public abstract class AbstractShape implements Shapes{

	// Common method for all shapes 
    /**
    * General method for comparing the shape areas.
    * @return 1 If shape area is greater than other.
    * @return 0 If shape area is equal with other.
    * @return -1 If shape area is less than other.
    * @param other Other shapes object that will be compared. 
    */
    public int compareTo(Shapes other) 
    {   
        int retVal=0;

        if(area()>other.area())
            retVal=1;
        if(area()==other.area())
            retVal=0;
        if(area()<other.area())
            retVal=-1;
        return retVal;
    }	
} 