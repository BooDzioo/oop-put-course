interface Forecast {
    double temperatureInCelsius();

    final class Fake implements Forecast {
        @Override
        public double temperatureInCelsius() {
            return 20.0;
        }
    }
}

class Weather {
    Forecast forecast;

    Weather(Forecast forecast) {
        this.forecast = forecast;
    }

    public double currentTemperatureInKelvins() {
        return forecast.temperatureInCelsius() + 273.15;
    }
}

class Ex1 {
    public static void main(String[] args) {
        Forecast forecast = new Forecast.Fake();
        Weather weather = new Weather(forecast);

        assert "293.15".equals(Double.toString(weather.currentTemperatureInKelvins()));
    }
}