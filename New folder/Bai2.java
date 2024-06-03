/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Buoi2;

import java.util.Scanner;

public class Bai2 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double sum =1.0;
        for(int i = 1; i<=n; ++i){
            sum += 1.0 / i;
        }
        System.out.println(sum);
    }
    
    
}
