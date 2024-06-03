/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Buoi2;


import java.util.Scanner;
class Bai1 {
    public static void main (String args[]){
        Scanner input = new Scanner(System.in);
        int num;
        int sum = 0;
        int count = 0;
        int largest = Integer.MIN_VALUE;
        int smallest = Integer.MAX_VALUE;

        System.out.println("nhap so (gap 0 thi dung lai): ");
        num = input.nextInt();

        while(num != 0) {
            sum += num;
            count++;
            if(num > largest) {
                largest = num;
            }
            if(num < smallest) {
                smallest = num;
            }

            num = input.nextInt();
        }
        double average = (double)sum / count;

        System.out.println("Average: " + average);
        System.out.println("Largest: " + largest);
        System.out.println("Smallest: " + smallest);

    }
}