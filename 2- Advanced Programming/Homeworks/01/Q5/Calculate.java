public class Calculate {
    public static Complex sum(Complex a,Complex b){
        Complex r=new Complex();
        r.setR(a.getR()+b.getR());
        r.setI(a.getI()+b.getI());
        return r;
    }
    public static Complex sub(Complex a,Complex b){
        Complex r=new Complex();
        r.setR(a.getR()-b.getR());
        r.setI(a.getI()-b.getI());
        return r;
    }
    public static Complex mul(Complex a,Complex b){
        Complex r=new Complex();
        r.setR(a.getR()*b.getR()-a.getI()*b.getI());
        r.setI(a.getR()*b.getI()+a.getI()* b.getR());
        return r;
    }
    public static Complex div(Complex a,Complex b){
        Complex r=new Complex();
        r=mul(a,b.getC());
        return r;
    }
}