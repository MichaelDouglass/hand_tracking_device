#ifndef ARDY_H
#define ARDY_H

#include "hand.h"
#include "button.h"
#include "leds.h"
#include "states.h"

class Ardy
{
  private:

    // objects
    Button button;
    LEDS leds;
    Hand hand;

  public:
    Ardy()
    {

    };

    ~Ardy() {};

    // TODO: JOYSTICK STUFF
    LEDS get_leds() { return this->leds; }

    void set_leds_state(int state) { this->leds.set_state(state); }
    int get_leds_state() { return this->leds.get_state(); }
    void blink_pulse()
    {
      if (get_leds_state() == OFF)
        return;
      this->leds.blink_LED();
    }
    // int get_joy_mod() { return this->joy.modifier(); }
    // void set_joy_sense(int sensitivity) { this->joy.set_sensitivity(sensitivity); }


    // PULSE GENERATOR STUFF
    // PulseGenerator get_pgen() { return this->pgen; }

    // void set_pgen_frq(int frq) { this->pgen.set_frequency(frq); }
    // void set_pgen_state(int state) { this->pgen.set_state(state); }

    // actually turn the pulse generator on
    // void pulse()
    // {
    //   this->pgen.pulse();
    // }

    // TODO: ULTRASONIC SENSOR STUFF
  //   Ultrasonic get_ultra() { return this->ultra; }
  //
  //   // set key features
  //   void set_ultra_state(int state) { this->ultra.set_state(state); }
  //   void set_ultra_trig(int trig) { this->ultra.set_trig(trig); }
  //   void set_ultra_echo(int echo) { this->ultra.set_echo(echo); }
  //   void set_pins(int trig, int echo)
  //   {
  //   	set_ultra_trig(trig);
  //   	set_ultra_echo(echo);
  //   }
  //
  //   // turn on ultrasonic
  //   void start_ultra()
  //   {
  //   	this->ultra.start();
  //   }
  //
  //   Lever get_lever() { return this->lever; }
  //   void set_lever_ang(int ang) { this->lever.set_ang(ang); }
  //   int get_lever_ang() { return this->lever.get_ang(); }
  //   void init_lever() { this->lever.init_attach(); }
  //
  //   // :CON functions
  //   PID get_pid() { return this->pid; }
  //
  //   float con_get_kp() {return this->pid.get_kp(); }
  //   void con_set_kp(float kp) { this->pid.set_kp(kp); }
  //
  //   float con_get_ki() {return this->pid.get_ki(); }
  //   void con_set_ki(float ki) { this->pid.set_ki(ki); }
  //
  //   float con_get_kd() {return this->pid.get_kd(); }
  //   void con_set_kd(float kd) { this->pid.set_kd(kd); }
  //
  //   int con_get_za() {return this->pid.get_zero_angle(); }
  //   void con_set_za(int za) { this->pid.set_zero_angle(za); }
  //
  //   int con_get_state() { return this->pid.get_state(); }
  //   void con_set_state(int state) { this->pid.set_state(state); }
  //
  //   int con_get_duration() { return this->pid.get_set_duration(); }
  //   void con_set_duration(int duration) { this->pid.set_set_duration(duration); }
  //
  //   void con_start_pid() { this->pid.ball_control(); }
  //   int con_get_servo() { return this->pid.get_servo(); }
  //
  //   // defined below
	// // gonna clean up file structur should we have time
  //   void pid_run();
  //   void joy_run();
  //
  //   void magic_change();
  //   void magic_move();
};


#endif
