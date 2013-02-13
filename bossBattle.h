#ifndef BOSS_BATTLE_H
#define BOSS_BATTLE_H

class BossBattle {
    private:
        Ship main;
        Boss boss;

    public:
        // Creates a boss battle frame.
        BossBattle(Ship mainShip, Boss Nessy);
        
        // Should add more attacks to Boss class to allow an interesting battle other than just sit and attack.
        void bossBattle();
        
        // Draws both HP bars, both names, attack menu, inventory, and flee.
        void update();
        
        // Just added these for semantics.
        Ship getMainShip();
        void setMainShip(Ship newShip);

        Boss getBoss();
        void setBoss(Boss newBoss);

}
#endif
