package lesson7;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;

class Problem {
    private final ArrayList<ArrayList<Integer>> suppliesPerElf = new ArrayList<ArrayList<Integer>>();

    public void printSupplies() {
        suppliesPerElf.forEach((n) -> n.forEach((calories) -> System.out.println(calories)));
    }
    public void load(String filePath) {
        try {
            File file = new File(filePath);
            Scanner myReader = new Scanner(file);

            suppliesPerElf.add(new ArrayList<Integer>());

            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();

                if(data.isEmpty()) suppliesPerElf.add(new ArrayList<Integer>());
                else suppliesPerElf.get(suppliesPerElf.size() - 1).add(Integer.valueOf(data));
            }



            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public void solve() {
        ArrayList<Integer> sums = new ArrayList<>();

        for (int i = 0; i < suppliesPerElf.size(); i++) {
            int sum = 0;

            for (int j = 0; j < suppliesPerElf.get(i).size(); j++) {
                sum += suppliesPerElf.get(i).get(j);
            }

            sums.add(sum);
        }

        ArrayList<Integer> sortedSums = new ArrayList(sums);
        Collections.sort(sortedSums);
        System.out.println(sortedSums);
        int maxCalories = sortedSums.get(sortedSums.size() - 1);
        int elfIndex = sums.indexOf(maxCalories);

        System.out.println("Max calories: " + maxCalories + " is carried by elf #" + elfIndex);

    }
}

class Day01 {
    public static void main(String[] args) {
        Problem problem = new Problem();

        problem.load("src/lesson7/Day01.txt");
        problem.solve();

    }
}