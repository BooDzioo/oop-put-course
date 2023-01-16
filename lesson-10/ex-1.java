interface Sequence {
    String printedSeq();
}

class Characters implements Sequence {
    private String text;

    Characters(String _text) {
        text = _text;
    }

    @Override
    public String printedSeq() {
        return text;
    }
}

class LowerCased implements Sequence {
    private Sequence characters;

    LowerCased(Sequence _characters) {
        characters = _characters;
    };

    @Override
    public String printedSeq() {
        return this.characters.printedSeq().toLowerCase();
    }
}

class Substring implements Sequence {
    private Sequence characters;
    private int begin;
    private int end;

    Substring(Sequence _characters, int _begin, int _end) {
        characters = _characters;
        begin = _begin;
        end = _end;
    };

    @Override
    public String printedSeq() {
        return this.characters.printedSeq().substring(begin, end);
    }
}

class Concatenation implements Sequence {
    private Sequence characters1;
    private Sequence characters2;

    Concatenation(Sequence _characters1, Sequence _characters2) {
        characters1 = _characters1;
        characters2 = _characters2;
    };

    @Override
    public String printedSeq() {
        return this.characters1.printedSeq() + this.characters2.printedSeq();
    }
}

class Ex1 {
    public static void main(String[] args) {
        Sequence chars = new Substring(
                    new LowerCased(
                        new Concatenation(new Characters("Abcd"), new Characters("Efgh"))
                    ),
                0, 5);

        System.out.println(chars.printedSeq());
    }
}