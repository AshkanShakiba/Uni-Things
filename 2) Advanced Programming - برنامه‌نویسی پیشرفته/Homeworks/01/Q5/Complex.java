public class Complex {
    private float r;
    private float i;
    public Complex(){
        r=i=0;
    }
    public void setR(float r){
        this.r=r;
    }
    public float getR(){
        return r;
    }
    public void setI(float i){
        this.i=i;
    }
    public float getI(){
        return i;
    }
    public Complex getC(){
        Complex c=new Complex();
        c.r=r/(r*r+i*i);
        c.i=-i/(r*r+i*i);
        return c;
    }
    public void print(){
        System.out.printf("%.2f%+.2fi\n",r,i);
    }
}