/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package baitap;

/**
 *

 */
public class bai3 {
    private double radius;
    // hanh vi cap nhat ban kinh
    public void setR(double r){
        this.radius = r;
    }
    //hanh vi truy van ban kinh
    public double getR(){
        return this.radius;
    }
    //truy van chu vi
    public double getP(){
        return 2*Math.PI*this.getR();
    }
    //truy van dien tich
    public double getS(){
        return Math.PI*this.getR()*this.getR();
    }
    public static void main(String[] args){
        bai3 c =new bai3();
        c.setR(5);
        System.out.printf("Ban kinh %5.3f \t chu vi %5.3f \t"+ 
                "dientich %5.3f",c.getR(),c.getP(),c.getS());
    }
}
