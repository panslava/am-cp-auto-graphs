import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { StrongConnectedComponent } from './strong-connected.component';

describe('StrongConnectedComponent', () => {
  let component: StrongConnectedComponent;
  let fixture: ComponentFixture<StrongConnectedComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ StrongConnectedComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(StrongConnectedComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
