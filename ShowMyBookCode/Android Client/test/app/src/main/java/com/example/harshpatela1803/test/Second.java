package com.example.harshpatela1803.test;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Second extends AppCompatActivity {

    public Button but2;

    public void second() {
        but2 = (Button) findViewById(R.id.but2);
        but2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }
    public Button but3;

    public void third() {
        but3 = (Button) findViewById(R.id.but3);
        but3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }
    public Button but4;

    public void four() {
        but4 = (Button) findViewById(R.id.but4);
        but4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }
    public Button but5;

    public void five() {
        but5 = (Button) findViewById(R.id.but5);
        but5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }public Button but6;

    public void six() {
        but6 = (Button) findViewById(R.id.but6);
        but6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }public Button but7;

    public void seven() {
        but7 = (Button) findViewById(R.id.but7);
        but7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }public Button but8;

    public void eight() {
        but8 = (Button) findViewById(R.id.but8);
        but8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }public Button but9;

    public void nine() {
        but9 = (Button) findViewById(R.id.but9);
        but9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent s = new Intent(Second.this, third.class);

                startActivity(s);
            }
        });
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        second();
        third();
        four();
        five();
        six();
        seven();
        eight();
        nine();

    }
}
