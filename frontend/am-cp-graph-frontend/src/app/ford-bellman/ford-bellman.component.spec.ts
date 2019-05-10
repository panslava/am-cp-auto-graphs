import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { FordBellmanComponent } from './ford-bellman.component';

describe('FordBellmanComponent', () => {
  let component: FordBellmanComponent;
  let fixture: ComponentFixture<FordBellmanComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ FordBellmanComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(FordBellmanComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
