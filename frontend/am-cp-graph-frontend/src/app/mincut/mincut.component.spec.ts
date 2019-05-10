import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MincutComponent } from './mincut.component';

describe('MincutComponent', () => {
  let component: MincutComponent;
  let fixture: ComponentFixture<MincutComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MincutComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MincutComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
