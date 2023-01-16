interface Sequence {
    String printedSeq();
}

interface SequenceDecorator{
    Sequence printedSeq();
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

class LowerCased implements SequenceDecorator {
    private Sequence characters;

    LowerCased(Sequence _characters) {
        characters = _characters;
    };

    @Override
    public Sequence printedSeq() {
        return new Characters(this.characters.printedSeq().toLowerCase());
    }
}

class Substring implements SequenceDecorator {
    private Sequence characters;
    private int begin;
    private int end;

    Substring(Sequence _characters, int _begin, int _end) {
        characters = _characters;
        begin = _begin;
        end = _end;
    };

    @Override
    public Sequence printedSeq() {
        return new Characters(this.characters.printedSeq().substring(begin, end));
    }
}

class Concatenation implements SequenceDecorator {
    private Sequence characters1;
    private Sequence characters2;

    Concatenation(Sequence _characters1, Sequence _characters2) {
        characters1 = _characters1;
        characters2 = _characters2;
    };

    @Override
    public Sequence printedSeq() {
        return new Characters(this.characters1.printedSeq() + this.characters2.printedSeq());
    }
}

class Ex1 {
    public static void main(String[] args) {
        Sequence chars = new Substring(new LowerCased(new Concatenation(new Characters("Abcd"), new Characters("Efgh")).printedSeq()).printedSeq(), 0, 5).printedSeq();

        System.out.println(chars.printedSeq());
    }
}