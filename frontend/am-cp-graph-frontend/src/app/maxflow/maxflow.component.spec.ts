import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MaxflowComponent } from './maxflow.component';

describe('MaxflowComponent', () => {
  let component: MaxflowComponent;
  let fixture: ComponentFixture<MaxflowComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MaxflowComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MaxflowComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
