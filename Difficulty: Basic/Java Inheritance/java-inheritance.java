class cls2 extends cls1 {
    void mul(int p, int q) { System.out.println(p * q); }

    void task(int p, int q) {
        // Add your code here.
        int a = (int)Math.pow(p,2);
        int b =(int)Math.pow(q,2);
        cls1 obj = new cls1();
        obj.add(a,b);
        
    }
}