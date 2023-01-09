import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicBoolean;

class Shiritori {
    private List<String> words = new ArrayList<String>();
    private boolean gameOver = false;

    public void play(String word) {
        AtomicBoolean isUnique = new AtomicBoolean(true);
        boolean hasProperBeginning = true;

        words.forEach((_word) -> {
            if(_word == word) isUnique.set(false);
        });

        if (words.size() > 0) {
            String lastWord = words.get(words.size() - 1);
            hasProperBeginning = lastWord.charAt(lastWord.length() - 1) == word.charAt(0);
        }

        if(isUnique.get() && hasProperBeginning) {
            words.add(word);
            printWords();

            return;
        }

        gameOver = true;
        System.out.println("Game over");
    }

    public void restart() {
        words = new ArrayList<String>();
        gameOver = false;

        System.out.println("Game restarted");
    }

    public void printWords() {
        System.out.println("Words:" + words.toString());
    }

}

class Ex1 {
    public static void main(String[] args) {
        Shiritori game = new Shiritori();

        game.play("test");
        game.play("test");

        game.restart();

        game.play("apple");
        game.play("ear");
        game.play("rhino");
    }
}